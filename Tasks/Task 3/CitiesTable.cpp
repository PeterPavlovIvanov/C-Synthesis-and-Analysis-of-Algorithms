#include "stdafx.h"

#include <atldbcli.h>

#include "Typedefs.h"

#include "CitiesTable.h"

#define QUOTE "/'"

BOOL CCitiesTable::ExecuteQuery(HRESULT hResult)
{
	CDBPropSet oDBPropSet(DBPROPSET_DBINIT);
	oDBPropSet.AddProperty(DBPROP_INIT_DATASOURCE, _T("DESKTOP-PFQL6JD\\SQLEXPRESS"));
	oDBPropSet.AddProperty(DBPROP_AUTH_INTEGRATED, _T("SSPI"));
	oDBPropSet.AddProperty(DBPROP_INIT_CATALOG, _T("PhoneBook"));
	oDBPropSet.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
	oDBPropSet.AddProperty(DBPROP_INIT_LCID, 1033L);
	oDBPropSet.AddProperty(DBPROP_INIT_PROMPT, static_cast<short>(4));

	// Свързваме се към базата данни
	m_hResult = m_oDataSource.Open(_T("SQLOLEDB.1"), &oDBPropSet);
	
	// Отваряме сесия
	m_hResult = m_oSession.Open(m_oDataSource);

	//Изпълняваме заявката
	m_hResult = Open(m_oSession, m_strQuery);

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
		if (MoveNext() == S_OK) 
		{
			CITIES* pCity = new CITIES();
			*pCity = m_recCity;

			oCitiesArray.Add(pCity);
		}
		else if (MoveNext() == DB_S_ENDOFROWSET)
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
	m_strQuery.Format(_T("SELECT * FROM CITIES WHERE ID = %d "), lID);

	if (FAILED(ExecuteQuery(hResult))) {
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	if (MoveNext() == S_OK)
	{
		recCities = m_recCity;
	}
	else if (MoveNext() == DB_S_ENDOFROWSET)
	{
		
	}
	else
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);
		return FALSE;
	}
		
	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::UpdateWhereID(const long lID, const CITIES& recCities, HRESULT hResult)
{
	CITIES oCity;
	SelectWhereID(lID, oCity, hResult);

	if (FAILED(ExecuteQuery(hResult))) {
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	/*long lUpdateCounter = recCities.lUPDATE_COUNTER;
	CString strCityName = recCities.szCITY_NAME;
	CString strRegion = recCities.szREGION;

	m_recCity.lUPDATE_COUNTER = lUpdateCounter;
	wcscpy_s(m_recCity.szCITY_NAME, strCityName);
	wcscpy_s(m_recCity.szREGION, strRegion);

	m_strQuery.Format(_T("UPDATE CITIES SET UPDATE_COUNTER = %d, CITY_NAME = %s%s%s, REGION = %s%s%s WHERE ID = %d"),
		 lUpdateCounter, QUOTE, strCityName, QUOTE, QUOTE, strRegion, QUOTE, lID);*/

	if (MoveNext() == S_OK)
	{
		m_recCity = recCities;
		SetData();
	}
	else
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}
	
	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::Insert(const CITIES& recCities, HRESULT hResult)
{
	/*long lUpdateCounter = recCities.lUPDATE_COUNTER;
	CString strCityName = recCities.szCITY_NAME;
	CString strRegion = recCities.szREGION;

	m_strQuery.Format(_T("INSERT INTO CITIES(UPDATE_COUNTER, CITY_NAME, REGION) VALUES(%d, %s%s%s, %s%s%s)"),
		lUpdateCounter, QUOTE, strCityName, QUOTE, QUOTE, strRegion, QUOTE);*/

	m_strQuery.Format(_T("SELECT TOP 0 * FROM CITIES"));

	if (FAILED(ExecuteQuery(hResult)))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}
	m_recCity = recCities;
//TODO

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::DeleteWhereID(const long lID, HRESULT hResult)
{
	m_strQuery.Format(_T("DELETE * FROM CITIES WHERE ID = %d"), lID);

	if (FAILED(ExecuteQuery(hResult)))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

void CCitiesTable::CloseCommandSessionConnection(CDataSource& oDataSource, CSession& oSession) 
{
	Close();
	oSession.Close();
	oDataSource.Close();
}