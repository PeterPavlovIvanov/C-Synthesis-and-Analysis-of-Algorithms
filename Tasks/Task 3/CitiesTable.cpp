#include "stdafx.h"

#include <atldbcli.h>

#include "Typedefs.h"

#include "CitiesTable.h"

#define INSERT_CITY "INSERT INTO CITIES(UPDATE_COUNTER, CITY_NAME, REGION) VALUES(%d, %s, %s)"
#define DELETE_CITY_BY_ID "DELETE * FROM CITIES WHERE ID = %d"

void CCitiesTable::ExecuteQuery()
{
	m_hResult = CoInitialize(0);

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
}

BOOL CCitiesTable::SelectAll(CCitiesArray& oCitiesArray) {
	m_strQuery = _T("SELECT * FROM CITIES");
	ExecuteQuery();

	if (FAILED(m_hResult))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	while (MoveNext() == S_OK)
	{
		CITIES* oCity = new CITIES();

		oCity->lID = m_recCity.lID;
		oCity->lUPDATE_COUNTER = m_recCity.lUPDATE_COUNTER;
		wcscpy_s(oCity->szCITY_NAME, m_recCity.szCITY_NAME);
		wcscpy_s(oCity->szREGION, m_recCity.szREGION);

		oCitiesArray.Add(oCity);
	}

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::SelectWhereID(const long lID, CITIES& recCities) {
	m_strQuery.Format(_T("SELECT * FROM CITIES WHERE ID = %d "), lID);
	ExecuteQuery();

	if (FAILED(m_hResult))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	while (MoveNext() == S_OK)
		recCities = m_recCity;

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::UpdateWhereID(const long lID, const CITIES& recCities) {
	long lUpdateCounter = recCities.lUPDATE_COUNTER;
	CString strCityName = recCities.szCITY_NAME;
	CString strRegion = recCities.szREGION;

	m_strQuery.Format(_T(
		"UPDATE CITIES SET UPDATE_COUNTER = %d, CITY_NAME = %s, REGION = %s WHERE ID = %d"),
		 lUpdateCounter, strCityName, strRegion, lID);
	ExecuteQuery();

	if (FAILED(m_hResult))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::Insert(const CITIES& recCities) {
	long lUpdateCounter = recCities.lUPDATE_COUNTER;
	CString strCityName = recCities.szCITY_NAME;
	CString strRegion = recCities.szREGION;

	m_strQuery.Format(_T(INSERT_CITY), lUpdateCounter, strCityName, strRegion);
	ExecuteQuery();

	if (FAILED(m_hResult))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

BOOL CCitiesTable::DeleteWhereID(const long lID) {
	m_strQuery.Format(_T(DELETE_CITY_BY_ID), lID);
	ExecuteQuery();

	if (FAILED(m_hResult))
	{
		CloseCommandSessionConnection(m_oDataSource, m_oSession);

		return FALSE;
	}

	CloseCommandSessionConnection(m_oDataSource, m_oSession);

	return TRUE;
};

void CCitiesTable::CloseCommandSessionConnection(CDataSource& oDataSource, CSession& oSession) {
	Close();
	oSession.Close();
	oDataSource.Close();
}