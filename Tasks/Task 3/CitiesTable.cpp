#include "stdafx.h"

#include <atlbase.h>

#include <atldbcli.h>

#include <atldbsch.h>

#include "Typedefs.h"

#include "CitiesTable.h"

#define QUOTE "/'"
#define BEGIN_TRAN "BEGIN TRANSACTION"
#define COMMIT_TRAN "COMMIT TRANSACTION"
#define ROLLBACK_TRAN "ROLLBACK TRANSACTION"

BOOL CCitiesTable::ExecuteQuery(HRESULT hResult)
{
	CDBPropSet oDBPropSet(DBPROPSET_DBINIT);
	oDBPropSet.AddProperty(DBPROP_INIT_DATASOURCE, _T("DESKTOP-PFQL6JD\\SQLEXPRESS"));
	oDBPropSet.AddProperty(DBPROP_AUTH_INTEGRATED, _T("SSPI"));
	oDBPropSet.AddProperty(DBPROP_INIT_CATALOG, _T("PhoneBook"));
	oDBPropSet.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
	oDBPropSet.AddProperty(DBPROP_INIT_LCID, 1033L);
	oDBPropSet.AddProperty(DBPROP_INIT_PROMPT, static_cast<short>(4));

	CDBPropSet pPropSet(DBPROPSET_ROWSET);
	pPropSet.AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	pPropSet.AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	pPropSet.AddProperty(DBPROP_IGetRow, true, DBPROPOPTIONS_OPTIONAL);
	pPropSet.AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
	pPropSet.AddProperty(DBPROP_IRowsetUpdate, true);
	pPropSet.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);

	// Свързваме се към базата данни
	m_hResult = m_oDataSource.Open(_T("SQLOLEDB.1"), &oDBPropSet);

	// Отваряме сесия
	m_hResult = m_oSession.Open(m_oDataSource);

	// Изпълняваме заявката
	m_hResult = Open(m_oSession, m_strQuery, &pPropSet);

	if (FAILED(hResult)) {
		return FALSE;
	}
	return TRUE;
}

BOOL CCitiesTable::SelectAll(CCitiesArray& oCitiesArray, HRESULT hResult)
{
	m_strQuery = _T("SELECT * FROM CITIES");

	if (FAILED(ExecuteQuery(hResult)))
	{
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
			CloseCommandSessionConnection(m_oDataSource, m_oSession);
			return FALSE;
		}
	}

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::SelectWhereID(const long lID, CITIES& recCities, HRESULT hResult)
{
	if (FAILED(SelectByID(lID, recCities))) {
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::UpdateWhereID(const long lID, const CITIES& recCities, HRESULT hResult)
{
	CITIES oCity;

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
	//SelectByID(lID, oCity);

	//if (m_recCity.lUPDATE_COUNTER - 1 != oCity.lUPDATE_COUNTER)
	//{
	//	m_oSession.Abort();
	//}
	//else
	//{
	//	m_oSession.Commit();
	//}

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::Insert(const CITIES& recCities, HRESULT hResult)
{

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