#pragma once

#include <atldbcli.h>

///<summary>Клас за създаване на настройки за връзката с DB</summary>
class CPropertiesConnectionDB {
public:
	///<summary>Създава настройки за връзката с DB</summary>
	void SetProperties(CDBPropSet& oCDBPropSet, CDBPropSet& pPropSet);
};