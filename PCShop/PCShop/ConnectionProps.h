#pragma once

#include <atldbcli.h>

class ConnectionProps
{
public:
	void SetPropertiesDB(CDBPropSet& dBPropSet);

	void SetPropertiesRows(CDBPropSet& propSet);
};