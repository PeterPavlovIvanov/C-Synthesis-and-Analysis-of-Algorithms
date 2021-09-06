#pragma once
#include "TypeDefs.h"
#include "ShelvesBusinessLogic.h"
#include "RacksBusinessLogic.h"
#include "UpdateCodes.h"

// ShelvesDocument document

class ShelvesDocument : public CDocument
{
protected:
	DECLARE_DYNCREATE(ShelvesDocument)
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnNewDocument();

public:
	ShelvesDocument();
	virtual ~ShelvesDocument();
#ifndef _WIN32_WCE
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public:
	BOOL SelectAll();

	BOOL SelectByID(int id, SHELVES& shelf);

	BOOL DeleteByID(int id);

	BOOL UpdateShelf (SHELVES& shelf);

	BOOL InsertShelf(SHELVES& shelf);

	ShelvesArray& GetShelvesArray()
	{
		return shelvesArray;
	}

	RacksArray& GetRacksArray()
	{
		return racksArray;
	}

	void OnUpdateAllViews(UpdateCodes updateCodeN, SHELVES shelf);

	//Business Logic objects
public:
	ShelvesBusinessLogic shelvesBusinessLogic;
	RacksBusinessLogic racksBusinessLogic;

	//Array Storages for data display
private:
	ShelvesArray shelvesArray; //масив хранилище на документа за view-тата
	RacksArray racksArray; //масив хранилище на документа за view-тата
};
