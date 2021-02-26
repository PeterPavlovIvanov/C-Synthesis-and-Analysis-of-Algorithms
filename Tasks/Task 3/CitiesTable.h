#pragma once

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
	BOOL SelectAll(CCitiesArray& oCitiesArray, HRESULT hResult);

	///<summary>Взима град по посочено ID</summary>
	BOOL SelectWhereID(const long lID, CITIES& recCities, HRESULT hResult);

	///<summary>Update-ва град по посочено ID</summary>
	BOOL UpdateWhereID(const long lID, const CITIES& recCities, HRESULT hResult);

	///<summary>Вмъква град в таблицата CITIES</summary>
	BOOL Insert(const CITIES& recCities, HRESULT hResult);

	///<summary>Изтрива град по посочено ID</summary>
	BOOL DeleteWhereID(const long lID, HRESULT hResult);

	///<summary>Прави връзката с DB</summary>
	BOOL ExecuteQuery(HRESULT hResult);

	///<summary>Прекратява връзката с DB</summary>
	void CloseCommandSessionConnection(CDataSource& oDataSource, CSession& oSession);

	///<summary>Update-ва град по посочено ID без да затваря сесията</summary>
	BOOL SelectByID(const long lID, CITIES& recCities);

	//Members...
private:
	HRESULT m_hResult;
	CString m_strQuery;
	CSession m_oSession;
	CDataSource m_oDataSource;
};