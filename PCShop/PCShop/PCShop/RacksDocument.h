#pragma once
#include "TypeDefs.h"
#include "RacksBusinessLogic.h"

// RacksDocument document

class RacksDocument : public CDocument
{
protected:
	DECLARE_DYNCREATE(RacksDocument)
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnNewDocument();

public:
	RacksDocument();
	virtual ~RacksDocument();
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

	BOOL SelectByID(int id, RACKS& rack);

	BOOL DeleteByID(int id);

	BOOL UpdateRack(RACKS& rack);

	BOOL InsertRack(RACKS& rack);

	RacksArray& GetRacksArray()
	{
		return racksArray;
	}

	//void OnUpdateAllViews(UpdateCodes eUpdateCode, RACKS rack);

public:
	RacksBusinessLogic racksBusinessLogic;

private:
	RacksArray racksArray; //масив хранилище на документа за view-тата
};
