#pragma once

#include <atldbcli.h>
#include "MemoryArray.h"
#include "ConnectionProps.h"
#include "DBConnection.h"

///<summary>Клас за работа с таблица от базата данни</summary>
template <class AccessorType, class StructureType>
class AbstractTable : protected CCommand<CAccessor<AccessorType>>
{
	//Constructors...
public:
	///<summary>Default Конструктор</summary>
	AbstractTable()
	{
		isSessionPassedFromOutSide = false;
		pointerSession = new CSession();
	};

	///<summary>Конструктор по сесия</summary>
	AbstractTable(CSession* session)
	{
		pointerSession = session;
		isSessionPassedFromOutSide = true;
	};

	~AbstractTable()
	{
		if (!isSessionPassedFromOutSide)
			delete pointerSession;
	}

	//Methods...
public:
	/// <summary>Взима всички структури от таблицата AccessorType</summary>
	/// <param name="oStructureArray">Контейнер за резултата</param>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL SelectAll(MemoryArray<StructureType>& structureArray)
	{
		HRESULT hResult = S_OK;
		CString strQuery;
		strQuery.Format(_T("SELECT * FROM %s"), tableName);

		if (FAILED(OpenSession()))
			return FALSE;

		if (FAILED(ExecuteQuery(strQuery)))
		{
			Close();
			return FALSE;
		}

		while (true)
		{
			hResult = MoveNext();
			if (hResult == S_OK)
			{
				Trim();
				StructureType* abstractStructure = new StructureType();
				*abstractStructure = GetRowSet();

				structureArray.Add(abstractStructure);
			}
			else if (hResult == DB_S_ENDOFROWSET)
			{
				break;
			}
			else
			{
				CloseSession();
				Close();
				return FALSE;
			}
		}
		Close();
		return TRUE;
	};

	/// <summary>Взима структура от таблицата по посочено ID</summary>
	/// <param name="lID">ID на търсената структура</param>
	/// <param name="recStructure">Структура за пазене на резултата</param>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL SelectWhereID(long lID, StructureType& recStructure)
	{
		if (FAILED(OpenSession()))
			return FALSE;

		if (FAILED(SelectByID(lID, recStructure)))
		{
			CloseSession();
			Close();
			return FALSE;
		}

		CloseSession();
		Close();
		return TRUE;
	};

	/// <summary>Update-ва структура по посочено ID</summary>
	/// <param name="lID">ID на дадената структура</param>
	/// <param name="recStructure">Структура съдържащ новите данни</param>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL UpdateWhereID(long lID, StructureType& recStructure)
	{
		StructureType structureContainer;

		if (FAILED(OpenSession()))
			return FALSE;

		if (FAILED(OpenTransaction()))
			return FALSE;

		if (FAILED(SelectByID(lID, structureContainer)))
		{
			pointerSession->Abort();
			CloseSession();
			Close();
			return FALSE;
		}

		//инкрементираме Update_Counter-а
		GetRowSet() = recStructure;

		if (FAILED(SetData(1)))
		{
			pointerSession->Abort();
			CloseSession();
			Close();
			return FALSE;
		}

		CommitTransaction();
		CloseSession();
		Close();
		return TRUE;
	};

	/// <summary>Вмъква структура в таблицата AccessorType</summary>
	/// <param name="recStructure">Структура съдържаща новите данни</param>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL Insert(StructureType& recStructure)
	{
		HRESULT hResult = S_OK;
		CString strQuery;

		strQuery.Format(_T("SELECT TOP 0 * FROM %s"), tableName);

		if (FAILED(OpenSession()))
			return FALSE;

		if (FAILED(OpenTransaction()))
			return FALSE;

		if (FAILED(ExecuteQuery(strQuery)))
		{
			pointerSession->Abort();
			CloseSession();
			Close();
			return FALSE;
		}

		hResult = MoveNext();
		Trim();

		if (FAILED(hResult))
		{
			pointerSession->Abort();
			CloseSession();
			Close();
			return FALSE;
		}

		GetRowSet() = recStructure;
		hResult = __super::Insert(1);

		if (FAILED(hResult))
		{
			CloseSession();
			Close();
			return FALSE;
		}

		MoveNext();
		Trim();
		recStructure = GetRowSet();

		CommitTransaction();
		CloseSession();
		Close();
		return TRUE;
	};

	/// <summary>Изтрива структура по посочено ID</summary>
	/// <param name="lID">ID на дадената структура</param>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL DeleteWhereID(const long lID)
	{
		HRESULT hResult = S_OK;

		StructureType oStructure;

		if (FAILED(OpenSession()))
			return FALSE;

		if (FAILED(OpenTransaction()))
			return FALSE;

		if (FAILED(SelectByID(lID, oStructure)))
		{
			pointerSession->Abort();
			CloseSession();
			return FALSE;
		}

		hResult = Delete();

		if (FAILED(hResult))
		{
			CloseSession();
			return FALSE;
		}

		CommitTransaction();
		CloseSession();
		Close();
		return TRUE;
	};

	/// <summary>Прави връзката с DB</summary>
	/// <param name="strQuery">Заявката за изпълнение</param>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL ExecuteQuery(CString strQuery)
	{
		HRESULT hResult = S_OK;
		CDBPropSet pPropSet(DBPROPSET_ROWSET);
		ConnectionProps oPropConDB;
		oPropConDB.SetPropertiesRows(pPropSet);

		hResult = Open(*pointerSession, strQuery, &pPropSet);

		if (FAILED(hResult))
		{
			return FALSE;
		}
		return TRUE;
	};

private:
	/// <summary>Взима структура по ID и я запазва в recStructure, не знае за съществуването на сесията</summary>
	/// <param name="lID">ID на дадената структура</param>
	/// <param name="recStructure">Структура за пазене на резултата</param>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL SelectByID(const long lID, StructureType& recStructure)
	{
		CString strQuery;
		strQuery.Format(_T("SELECT * FROM %s WHERE ID = %d"), tableName, lID);

		ExecuteQuery(strQuery);

		if (MoveNext() == S_OK)
		{
			Trim();
			recStructure = GetRowSet();
		}
		else
		{

			return FALSE;
		}
		return TRUE;
	};

	///<summary>Отваря сесията ако не е подадена отвън</summary>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL OpenSession()
	{
		if (!isSessionPassedFromOutSide)
			if (FAILED(pointerSession->Open(DBConnection::GetInstance().GetDataSource())))
			{
				Close();
				return FALSE;
			}

		return TRUE;
	}

	///<summary>Затваря сесията ако не е подадена отвън</summary>
	void CloseSession()
	{
		if (!isSessionPassedFromOutSide)
			pointerSession->Close();
	}

	///<summary>Отваря танзакция ако сесията не е подадена отвън</summary>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL OpenTransaction()
	{
		if (!isSessionPassedFromOutSide)
			if (FAILED(pointerSession->StartTransaction()))
			{
				CloseSession();
				return FALSE;
			}
		return TRUE;
	}

	///<summary>Commit-ва транзакция ако сесията не е подадена отвън</summary>
	/// <returns>Булева стойност отговаряща дали методът е приключил успешно</returns>
	BOOL CommitTransaction()
	{
		if (!isSessionPassedFromOutSide)
			if (FAILED(pointerSession->Commit()))
			{
				CloseSession();
				return FALSE;
			}
		return TRUE;
	}

	///<summary>Pure Virtual метод взимащ rowset-а</summary>
	///<returns>връща rowset-а</returns>
	virtual StructureType& GetRowSet() = 0;

	///<summary>Pure Virtual метод взимащ UpdateCounter-а</summary>
	///<returns>връща UpdateCounter-а</returns>
	//virtual long* GetUpdateCounter(StructureType& recStructure) = 0;

	///<summary>Премахва ненужните space-ове, добавени от MoveNext()</summary>
	virtual void Trim() = 0;

	//Members...
private:
	///<summary>Булева променлива кой ноструктор е използван</summary>
	bool isSessionPassedFromOutSide;

protected:
	/// <summary>Поинтър към Текуща сесия</summary>
	CSession* pointerSession;

protected:
	/// <summary>Име на таблицата</summary>
	CString tableName;
};
