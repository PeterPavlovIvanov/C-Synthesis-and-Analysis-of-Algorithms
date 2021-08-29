#include "stdafx.h"
#include <atlbase.h>
#include <atldbcli.h>
#include <atldbsch.h>
#include "ConnectionProps.h"

void ConnectionProps::SetPropertiesDB(CDBPropSet& dBPropSet)
{
	dBPropSet.AddProperty(DBPROP_INIT_DATASOURCE, _T("TEODOR"));
	dBPropSet.AddProperty(DBPROP_AUTH_INTEGRATED, _T("SSPI"));
	dBPropSet.AddProperty(DBPROP_INIT_CATALOG, _T("PCShop"));
	dBPropSet.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
	dBPropSet.AddProperty(DBPROP_INIT_LCID, 1033L);
	dBPropSet.AddProperty(DBPROP_INIT_PROMPT, static_cast<short>(4));
};

void ConnectionProps::SetPropertiesRows(CDBPropSet& propSet)
{
	propSet.AddProperty(DBPROP_CANFETCHBACKWARDS, true);
	propSet.AddProperty(DBPROP_IRowsetScroll, true);
	propSet.AddProperty(DBPROP_IRowsetChange, true);
	propSet.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
};