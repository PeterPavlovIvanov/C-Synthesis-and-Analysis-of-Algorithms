#pragma once
#include "TypeDefs.h"
#include "BrandsBusinessLogic.h"

// BrandsDocument document

class BrandsDocument : public CDocument
{
protected:
	DECLARE_DYNCREATE(BrandsDocument)
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnNewDocument();

public:
	BrandsDocument();
	virtual ~BrandsDocument();
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

	BOOL SelectByID(int id, BRANDS& brand);

	BOOL DeleteByID(int id);

	BOOL UpdateBrand(BRANDS& brand);

	BOOL InsertBrand(BRANDS& brand);

	BrandsArray& GetBrandsArray()
	{
		return brandsArray;
	}

	//void OnUpdateAllViews(UpdateCodes eUpdateCode, RACKS rack);

public:
	BrandsBusinessLogic brandsBusinessLogic;

private:
	BrandsArray brandsArray; //масив хранилище на документа за view-тата
};
