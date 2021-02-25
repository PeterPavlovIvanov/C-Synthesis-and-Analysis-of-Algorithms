﻿#pragma once

#include <atldbcli.h>

#include "Typedefs.h"

class CCitiesAccessor
{
protected:
	CITIES m_recCity;

	BEGIN_ACCESSOR_MAP(CCitiesAccessor, 2)
		BEGIN_ACCESSOR(0, true)
		COLUMN_ENTRY(1, m_recCity.lID)
		END_ACCESSOR()

		BEGIN_ACCESSOR(1, true)
		COLUMN_ENTRY(2, m_recCity.lUPDATE_COUNTER)
		COLUMN_ENTRY(3, m_recCity.szCITY_NAME)
		COLUMN_ENTRY(4, m_recCity.szREGION)
		END_ACCESSOR()
	END_ACCESSOR_MAP()
};

///<summary>Клас за работа с таблица CITIES</summary>
class CCitiesTable : private CCommand<CAccessor<CCitiesAccessor>> {
public:
	///<summary>Взима всички градове от таблицата CITIES</summary>
	BOOL SelectAll(CCitiesArray& oCitiesArray);

	///<summary>Взима град по посочено ID</summary>
	BOOL SelectWhereID(const long lID, CITIES& recCities);

	///<summary>Update-ва град по посочено ID</summary>
	BOOL UpdateWhereID(const long lID, const CITIES& recCities);

	///<summary>Вмъква град в таблицата CITIES</summary>
	BOOL Insert(const CITIES& recCities);

	///<summary>Изтрива град по посочено ID</summary>
	BOOL DeleteWhereID(const long lID);

	///<summary>Прави връзката с DB</summary>
	void ExecuteQuery();

	void CloseCommandSessionConnection(CDataSource& oDataSource, CSession& oSession);

	//Members...
private:
	HRESULT m_hResult;
	CString m_strQuery;
	CSession m_oSession;
	CDataSource m_oDataSource;
};