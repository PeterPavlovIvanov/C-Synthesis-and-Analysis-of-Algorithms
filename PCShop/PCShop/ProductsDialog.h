#pragma once
#include "DialogModes.h"
#include "ProductTypesView.h"

// ProductsDialog dialog

class ProductsDialog : public CDialog
{
	DECLARE_DYNAMIC(ProductsDialog)

public:
	ProductsDialog(PRODUCTS& product, PRODUCT_TYPES & productType, ModelsArray& modelsArray,
		CategoriesArray& categoriesArray, BrandsArray& brandsArray, ShelvesArray& shelvesArray, RacksArray& racksArray, DialogModes dialogMode,
		CWnd* pParent = NULL);   // standard constructor
	virtual ~ProductsDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRODUCTS_DIALOG };
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

	void FillComboBoxRacks();

	void FillComboBoxShelves();

private:
	//Members
	// ----------------
private:
	DialogModes dialogMode;

	PRODUCTS& openProduct;
	PRODUCT_TYPES& productType;
	ModelsArray& modelsArray;
	CategoriesArray& categoriesArray;
	BrandsArray& brandsArray;
	RacksArray& racksArray;
	ShelvesArray& shelvesArray;

public:
	CEdit editSerialID;
	CEdit editName;
	CEdit editPrice;
	CEdit editSize;
	CEdit editDescription;
	CEdit editAddressDate;
	CEdit editRegisterDate;
	CEdit editSoldDate;
	CComboBox comboBrands;
	CComboBox comboModels;
	CComboBox comboCategories;
	CComboBox comboShelves;
	CComboBox comboRacks;

	CString dlgCaption;
};
