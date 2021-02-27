#include "stdafx.h"

#include <atlbase.h>

#include <atldbcli.h>

#include <atldbsch.h>

#include "Typedefs.h"

#include "CitiesTable.h"

#include "PropertiesConnectionDB.h"

#define QUOTE "/'"
#define BEGIN_TRAN "BEGIN TRANSACTION"
#define COMMIT_TRAN "COMMIT TRANSACTION"
#define ROLLBACK_TRAN "ROLLBACK TRANSACTION"

CCitiesTable::CCitiesTable()
{
	CDBPropSet oDBPropSet(DBPROPSET_DBINIT);
	CDBPropSet pPropSet(DBPROPSET_ROWSET);

	CPropertiesConnectionDB oPropConDB;
	oPropConDB.SetProperties(oDBPropSet, pPropSet);

	m_pPropSet = pPropSet;
	m_oDBPropSet = oDBPropSet;
}

BOOL CCitiesTable::ExecuteQuery(HRESULT hResult)
{
	m_hResult = Open(m_oSession, m_strQuery, &m_pPropSet);

	if (FAILED(hResult)) {
		return FALSE;
	}
	return TRUE;
}

BOOL CCitiesTable::CreateCommandSessionConnection(CDBPropSet& oDBPropSet)
{
	HRESULT hResult = CoInitialize(0);

	// Свързваме се към базата данни
	hResult = m_oDataSource.Open(_T("SQLOLEDB.1"), &oDBPropSet);

	// Отваряме сесия
	hResult = m_oSession.Open(m_oDataSource);

	if (FAILED(hResult)) {
		return FALSE;
	}
	return TRUE;
}

void CCitiesTable::CloseCommandSessionConnection(CDataSource& oDataSource, CSession& oSession)
{
	Close();
	oSession.Close();
	oDataSource.Close();
}

BOOL CCitiesTable::SelectByID(const long lID, CITIES& recCities)
{
	m_strQuery.Format(_T("SELECT * FROM CITIES WHERE ID = %d"), lID);

	HRESULT hResult = CoInitialize(0);
	ExecuteQuery(hResult);

	if (MoveNext() == S_OK)
	{
		recCities = m_recCity;
	}
	else
	{
		return FALSE;
	}
	return TRUE;
}

BOOL CCitiesTable::SelectAll(CCitiesArray& oCitiesArray, HRESULT hResult)
{
	if (FAILED(CreateCommandSessionConnection(m_oDBPropSet)))
	{
		return FALSE;
	}

	m_strQuery = _T("SELECT * FROM CITIES");
	m_oSession.StartTransaction();

	if (FAILED(ExecuteQuery(hResult)))
	{
		m_oSession.Abort();
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	while (true)
	{
		HRESULT hResultMove = MoveNext();
		if (hResultMove == S_OK)
		{
			CITIES* pCity = new CITIES();
			*pCity = m_recCity;

			oCitiesArray.Add(pCity);
		}
		else if (hResultMove == DB_S_ENDOFROWSET)
		{
			break;
		}
		else
		{
			m_oSession.Abort();
			CloseCommandSessionConnection(m_oDataSource, m_oSession);
			return FALSE;
		}
	}

	m_oSession.Commit();
	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::SelectWhereID(const long lID, CITIES& recCities, HRESULT hResult)
{
	if (FAILED(CreateCommandSessionConnection(m_oDBPropSet)))
	{
		return FALSE;
	}

	m_oSession.StartTransaction();

	if (FAILED(SelectByID(lID, recCities))) {
		m_oSession.Abort();
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	m_oSession.Commit();
	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::UpdateWhereID(const long lID, const CITIES& recCities, HRESULT hResult)
{
	if (FAILED(CreateCommandSessionConnection(m_oDBPropSet)))
	{
		return FALSE;
	}

	CITIES oCity;
	//m_oSession.StartTransaction();

	if (FAILED(SelectByID(lID, oCity))) {
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	int nUpdateCounter = m_recCity.lUPDATE_COUNTER;
	m_recCity = recCities;
	m_recCity.lUPDATE_COUNTER = nUpdateCounter + 1;
	hResult = SetData(1);

	if (FAILED(hResult))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	UpdateAll();
	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::Insert(const CITIES& recCities, HRESULT hResult)
{
	if (FAILED(CreateCommandSessionConnection(m_oDBPropSet)))
	{
		return FALSE;
	}

	m_strQuery.Format(_T("SELECT TOP 0 * FROM CITIES"));

	if (FAILED(ExecuteQuery(hResult)))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	hResult = MoveNext();

	if (FAILED(hResult))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}
	
	m_recCity = recCities;
	CRowset::Insert(1);
	UpdateAll();

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::DeleteWhereID(const long lID, HRESULT hResult)
{
	if (FAILED(CreateCommandSessionConnection(m_oDBPropSet)))
	{
		return FALSE;
	}

	CITIES oCity;
	if (FAILED(SelectByID(lID, oCity)))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	Delete();
	UpdateAll();

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

