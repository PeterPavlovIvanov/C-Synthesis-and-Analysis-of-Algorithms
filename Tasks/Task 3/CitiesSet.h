
// CitiesSet.h: interface of the CCitiesSet class
//


#pragma once

// code generated on Monday, February 22, 2021, 2:22 PM

class CCitiesSetAccessor
{
public:
	LONG m_ID;
	LONG m_UPDATE_COUNTER;
	TCHAR m_CITY_NAME[257];
	TCHAR m_REGION[257];

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwUPDATE_COUNTERStatus;
	DBSTATUS m_dwCITY_NAMEStatus;
	DBSTATUS m_dwREGIONStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwUPDATE_COUNTERLength;
	DBLENGTH m_dwCITY_NAMELength;
	DBLENGTH m_dwREGIONLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		/*pPropSet->AddProperty(DBPROP_INIT_DATASOURCE, _T("DESKTOP-PFQL6JD\\SQLEXPRESS"));
		pPropSet->AddProperty(DBPROP_AUTH_INTEGRATED, _T("SSPI"));
		pPropSet->AddProperty(DBPROP_INIT_CATALOG, _T("PhoneBook"));
		pPropSet->AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
		pPropSet->AddProperty(DBPROP_INIT_LCID, 1033L);
		pPropSet->AddProperty(DBPROP_INIT_PROMPT, static_cast<short>(4));*/
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
		hr = _db.OpenFromInitializationString(L"Provider=SQLNCLI11.1;Integrated Security=SSPI;Persist Security Info=False;User ID=\"\";Initial Catalog=PhoneBook;Data Source=DESKTOP-PFQL6JD\\SQLEXPRESS;Use Procedure for Prepare=1;Auto Translate=True;Packet Size=4096;Workstation ID=DESKTOP-PFQL6JD;Initial File Name=\"\";Use Encryption for Data=False;Tag with column collation when possible=False;MARS Connection=False;DataTypeCompatibility=0;Trust Server Certificate=False;Application Intent=READWRITE");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	BEGIN_COLUMN_MAP(CCitiesSetAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_UPDATE_COUNTER, m_dwUPDATE_COUNTERLength, m_dwUPDATE_COUNTERStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_CITY_NAME, m_dwCITY_NAMELength, m_dwCITY_NAMEStatus)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_REGION, m_dwREGIONLength, m_dwREGIONStatus)
	END_COLUMN_MAP()
};

class CCitiesSet : public CTable<CAccessor<CCitiesSetAccessor> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
		HRESULT hr = Open(m_session, L"dbo.CITIES", pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	void CloseAll()
	{
		Close();
		CloseDataSource();
	}
};

