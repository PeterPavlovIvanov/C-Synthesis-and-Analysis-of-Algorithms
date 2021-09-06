
// PCShopSet.h: interface of the CPCShopSet class
//


#pragma once

// code generated on Saturday, August 7, 2021, 7:43 PM

class CPCShopSetAccessor
{
public:
	LONG m_ID;
	TCHAR m_RACK_NAME[257];

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwIDStatus;
	DBSTATUS m_dwRACK_NAMEStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwIDLength;
	DBLENGTH m_dwRACK_NAMELength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
// #error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
		hr = _db.OpenFromInitializationString(L"Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;User ID=\"\";Initial Catalog=PCShop;Data Source=TEODOR;Use Procedure for Prepare=1;Auto Translate=True;Packet Size=4096;Workstation ID=TEODOR;Initial File Name=\"\";Use Encryption for Data=False;Tag with column collation when possible=False;MARS Connection=False;DataTypeCompatibility=0;Trust Server Certificate=False;Server SPN=NTLM;Application Intent=READWRITE");
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

	BEGIN_COLUMN_MAP(CPCShopSetAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_ID, m_dwIDLength, m_dwIDStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_RACK_NAME, m_dwRACK_NAMELength, m_dwRACK_NAMEStatus)
	END_COLUMN_MAP()
};

class CPCShopSet : public CTable<CAccessor<CPCShopSetAccessor> >
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
		HRESULT hr = Open(m_session, L"dbo.RACKS", pPropSet);
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

