#include "stdafx.h"
#include "DBConnection.h"

DBConnection DBConnection::instance;

DBConnection& DBConnection::GetInstance()
{
	return instance;
};

HRESULT DBConnection::CreateConnection()
{
	CDBPropSet dbPropSet(DBPROPSET_DBINIT);
	ConnectionProps propConDB;
	propConDB.SetPropertiesDB(dbPropSet);

	// Свързваме се към базата данни
	if (FAILED(dataSource.Open(_T("SQLOLEDB.1"), &dbPropSet)))
		return 0;
	
	return TRUE;
};

void  DBConnection::CloseConnection()
{
	dataSource.Close();
};

CDataSource& DBConnection::GetDataSource()
{
	return dataSource;
};