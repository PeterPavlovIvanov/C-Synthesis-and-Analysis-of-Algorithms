#include "stdafx.h"

#include <atlbase.h>

#include <atldbcli.h>

#include <atldbsch.h>

#include "PropertiesConnectionDB.h"

void CPropertiesConnectionDB::SetProperties(CDBPropSet& oDBPropSet, CDBPropSet& pPropSet)
{
	oDBPropSet.AddProperty(DBPROP_INIT_DATASOURCE, _T("DESKTOP-PFQL6JD\\SQLEXPRESS"));
	oDBPropSet.AddProperty(DBPROP_AUTH_INTEGRATED, _T("SSPI"));
	oDBPropSet.AddProperty(DBPROP_INIT_CATALOG, _T("PhoneBook"));
	oDBPropSet.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
	oDBPropSet.AddProperty(DBPROP_INIT_LCID, 1033L);
	oDBPropSet.AddProperty(DBPROP_INIT_PROMPT, static_cast<short>(4));

	pPropSet.AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	pPropSet.AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	pPropSet.AddProperty(DBPROP_IGetRow, true, DBPROPOPTIONS_OPTIONAL);
	pPropSet.AddProperty(DBPROP_IRowsetChange, true, DBPROPOPTIONS_OPTIONAL);
	pPropSet.AddProperty(DBPROP_IRowsetUpdate, true);
	pPropSet.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
}