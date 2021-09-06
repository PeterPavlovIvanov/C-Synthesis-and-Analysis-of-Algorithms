#pragma once
#include "TypeDefs.h"
#include "CategoriesBusinessLogic.h"
#include "ModelsBusinessLogic.h"
#include "BrandsBusinessLogic.h"

// ModelsDocument document

class ModelsDocument : public CDocument
{
protected:
	DECLARE_DYNCREATE(ModelsDocument)
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnNewDocument();

public:
	ModelsDocument();
	virtual ~ModelsDocument();
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

	BOOL SelectByID(int id, MODELS& model);

	BOOL DeleteByID(int id);

	BOOL UpdateModel(MODELS& model);

	BOOL InsertModel(MODELS& model);

	ModelsArray& GetModelsArray()
	{
		return modelsArray;
	}

	BrandsArray& GetBrandsArray()
	{
		return brandsArray;
	}

	//void OnUpdateAllViews(UpdateCodes eUpdateCode, RACKS rack);

public:
	ModelsBusinessLogic modelsBusinessLogic;
	BrandsBusinessLogic brandsBusinessLogic;

	//Array Storages for displaying data
private:
	ModelsArray modelsArray; //масив хранилище на документа за view-тата
	BrandsArray brandsArray; //масив хранилище на документа за view-тата
};