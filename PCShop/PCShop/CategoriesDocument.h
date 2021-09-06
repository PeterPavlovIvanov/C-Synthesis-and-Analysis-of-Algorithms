#include "TypeDefs.h"
#include "CategoriesBusinessLogic.h"
#include "UpdateCodes.h"
#include "DialogModes.h"

// CategoriesDocument document

class CategoriesDocument : public CDocument
{
protected:
	DECLARE_DYNCREATE(CategoriesDocument)
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnNewDocument();

public:
	CategoriesDocument();
	virtual ~CategoriesDocument();
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

	BOOL SelectByID(int id, CATEGORIES& category);

	BOOL DeleteByID(int id);

	BOOL UpdateCategory(CATEGORIES& category);

	BOOL InsertCategory(CATEGORIES& category);

	CategoriesArray& GetCategoriesArray()
	{
		return categoriesArray;
	}

	void OnUpdateAllViews(UpdateCodes updateCodeN, CATEGORIES category);

public:
	CategoriesBusinessLogic categoriesBusinessLogic;

	//Array Storages for displaying data
private:
	CategoriesArray categoriesArray; //масив хранилище на документа за view-тата
};
