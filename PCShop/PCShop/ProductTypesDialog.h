#pragma once
#include "DialogModes.h"
#include "ProductTypesView.h"

// ProductTypesDialog dialog

class ProductTypesDialog : public CDialog
{
	DECLARE_DYNAMIC(ProductTypesDialog)

public:
	ProductTypesDialog(PRODUCT_TYPES& pt, ModelsArray& modelsArray, CategoriesArray& categoriesArray, BrandsArray& brandsArray, DialogModes dialogMode, CWnd* pParent = NULL);   // standard constructor
	virtual ~ProductTypesDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCT_TYPES_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	//Methods
	// ----------------
public:
	afx_msg void OnBnClickedOk();

	afx_msg void OnBnClickedCancel();

	void CleanFields();

	BOOL DialogToBuf();

	BOOL OnInitDialog() override;

	void SetCaption(DialogModes dialogModeToSet);

	void SetEditControlsCredentials();

	void FillComboBoxBrands();

	void FillComboBoxModels();

	void FillComboBoxCategories();

private:
	//Members
	// ----------------
private:
	DialogModes dialogMode;

	PRODUCT_TYPES& openProductType;
	ModelsArray& modelsArray;
	CategoriesArray& categoriesArray;
	BrandsArray& brandsArray;

public:
	CEdit editName;
	CEdit editPrice;
	CEdit editSize;
	CEdit editDescription;
	CEdit editQuantity;
	CComboBox comboBrands;
	CComboBox comboModels;
	CComboBox comboCategories;

	CString dlgCaption;
};