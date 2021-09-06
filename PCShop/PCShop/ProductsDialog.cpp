// ProductsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ProductsDialog.h"
#include "afxdialogex.h"


// ProductsDialog dialog

IMPLEMENT_DYNAMIC(ProductsDialog, CDialog)

ProductsDialog::ProductsDialog(PRODUCTS & product, PRODUCT_TYPES & productType, ModelsArray & modelsArray,
	CategoriesArray & categoriesArray, BrandsArray & brandsArray, ShelvesArray& shelvesArray, RacksArray& racksArray, DialogModes dialogMode, CWnd * pParent/*=NULL*/)
	: CDialog(IDD_PRODUCTS_DIALOG, pParent), openProduct(product), productType(productType), modelsArray(modelsArray), 
	categoriesArray(categoriesArray), brandsArray(brandsArray), shelvesArray(shelvesArray), racksArray(racksArray)
{
	SetCaption(dialogMode);
}

ProductsDialog::~ProductsDialog()
{
}

void ProductsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_P_SERIAL_NUM, editSerialID);
	DDX_Control(pDX, IDC_EDIT_P_ADDRESS_DATE, editAddressDate);
	DDX_Control(pDX, IDC_EDIT_P_DESCRIPTION, editDescription);
	DDX_Control(pDX, IDC_EDIT_P_NAME, editName);
	DDX_Control(pDX, IDC_EDIT_P_REGISTER_DATE, editRegisterDate);
	DDX_Control(pDX, IDC_EDIT_P_SIZE, editSize);
	DDX_Control(pDX, IDC_EDIT_P_SOLD_DATE, editSoldDate);
	DDX_Control(pDX, IDC_EDIT_P_PRICE, editPrice);
	DDX_Control(pDX, IDC_COMBO_P_BRAND, comboBrands);
	DDX_Control(pDX, IDC_COMBO_P_CATEGORY, comboCategories);
	DDX_Control(pDX, IDC_COMBO_P_MODEL, comboModels);
	DDX_Control(pDX, IDC_COMBO_P_SHELF, comboShelves);
	DDX_Control(pDX, IDC_COMBO_P_RACK, comboRacks);
}

void ProductsDialog::OnBnClickedOk()
{
	if (DialogToBuf() != TRUE)
		return;
	CDialog::OnOK();
}

void ProductsDialog::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

BOOL ProductsDialog::DialogToBuf()
{
	CString strWindowText;
	CString message; //error message
	BOOL bResult = TRUE;

	editAddressDate.GetWindowText(strWindowText);
	wcscpy_s(openProduct.addressDate, strWindowText);

	editSoldDate.GetWindowText(strWindowText);
	wcscpy_s(openProduct.soldDate, strWindowText);

	editRegisterDate.GetWindowText(strWindowText);
	wcscpy_s(openProduct.registerDate, strWindowText);

	editSerialID.GetWindowText(strWindowText);
	openProduct.serialID = _wtol(strWindowText);

	editName.GetWindowText(strWindowText);
	wcscpy_s(productType.productName, strWindowText);

	editPrice.GetWindowText(strWindowText);
	productType.price = _ttof(strWindowText);

	editDescription.GetWindowText(strWindowText);
	wcscpy_s(productType.description, strWindowText);

	editSize.GetWindowText(strWindowText);
	productType.productSize = _wtol(strWindowText);

	long index = comboBrands.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA brand must be selected."));
		bResult = FALSE;
	}
	productType.brandID = (long)comboBrands.GetItemData(index);

	index = comboCategories.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA category must be selected."));
		bResult = FALSE;
	}
	productType.categoryID = (long)comboCategories.GetItemData(index);

	index = comboModels.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA model must be selected."));
		bResult = FALSE;
	}
	productType.modelID = (long)comboModels.GetItemData(index);

	index = comboRacks.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA rack must be selected."));
		bResult = FALSE;
	}
	openProduct.rackID = (long)comboRacks.GetItemData(index);

	index = comboShelves.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA shelf must be selected."));
		bResult = FALSE;
	}
	openProduct.shelfID = (long)comboShelves.GetItemData(index);

	if (bResult != TRUE)
	{
		AfxMessageBox(message);
		return FALSE;
	}

	return TRUE;
}
BOOL ProductsDialog::OnInitDialog()
{
	__super::OnInitDialog();

	SetWindowText(dlgCaption);

	FillComboBoxBrands();
	FillComboBoxCategories();
	FillComboBoxModels();
	FillComboBoxShelves();
	FillComboBoxRacks();

	SetEditControlsCredentials();

	return TRUE;
}

void ProductsDialog::SetCaption(DialogModes dialogModeToSet)
{
	switch (dialogModeToSet)
	{
	case DialogModeUpdate:
		dlgCaption = _T("Update product");
		break;
	case DialogModeDelete:
		dlgCaption = _T("Are you sure you want to delete this product?");
		break;
	case DialogModePreview:
		dlgCaption = _T("Preview product");
		break;
	case DialogModeInsert:
		dlgCaption = _T("Add product");
		break;
	};

	this->dialogMode = dialogModeToSet;
}

void ProductsDialog::SetEditControlsCredentials()
{
	CString stringPrice, stringSize, stringID, stringAddressDate, stringSoldDate, stringRegisterDate;
	stringPrice.Format(_T("%.2f"), productType.price);
	stringSize.Format(_T("%d"), productType.productSize);
	stringID.Format(_T("%d"), openProduct.serialID);
	stringAddressDate.Format(_T("%s"), openProduct.addressDate);
	stringSoldDate.Format(_T("%s"), openProduct.soldDate);
	stringRegisterDate.Format(_T("%s"), openProduct.registerDate);

	SetDlgItemText(IDC_EDIT_P_DESCRIPTION, productType.description);
	SetDlgItemText(IDC_EDIT_P_NAME, productType.productName);
	SetDlgItemText(IDC_EDIT_P_PRICE, stringPrice);
	SetDlgItemText(IDC_EDIT_P_SIZE, stringSize);
	SetDlgItemText(IDC_EDIT_P_SERIAL_NUM, stringID);
	SetDlgItemText(IDC_EDIT_P_ADDRESS_DATE, stringAddressDate);
	SetDlgItemText(IDC_EDIT_P_REGISTER_DATE, stringRegisterDate);
	SetDlgItemText(IDC_EDIT_P_SOLD_DATE, stringSoldDate);

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		editDescription.SetReadOnly();
		editName.SetReadOnly();
		editPrice.SetReadOnly();
		editSize.SetReadOnly();
		editSerialID.SetReadOnly();
		comboBrands.EnableWindow(FALSE);
		comboCategories.EnableWindow(FALSE);
		comboModels.EnableWindow(FALSE);
	}
	else
	{
		editSerialID.SetWindowText(_T("Assigns automatically."));
		editSerialID.SetReadOnly();
	}
	
	if (dialogMode == DialogModes::DialogModePreview || dialogMode == DialogModes::DialogModeDelete)
	{
		editAddressDate.SetReadOnly();
		editRegisterDate.SetReadOnly();
		editSoldDate.SetReadOnly();
		comboBrands.EnableWindow(FALSE);
		comboCategories.EnableWindow(FALSE);
		comboModels.EnableWindow(FALSE);
		comboRacks.EnableWindow(FALSE);
		comboShelves.EnableWindow(FALSE);
	}
}

void ProductsDialog::FillComboBoxBrands()
{
	for (int i = 0; i < brandsArray.GetCount(); i++)
	{
		int index = comboBrands.AddString(brandsArray.GetAt(i)->brandName);
		comboBrands.SetItemData(index, brandsArray.GetAt(i)->ID);
	}

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		CString strBrandName;
		for (int i = 0; i < brandsArray.GetCount(); i++)
			if (productType.brandID == brandsArray.GetAt(i)->ID)
			{
				strBrandName.Format(_T("%s"), brandsArray.GetAt(i)->brandName);
				int index = comboBrands.SelectString(0, strBrandName);
				comboBrands.SetCurSel(index);

				break;
			}
	}
}

void ProductsDialog::FillComboBoxModels()
{
	for (int i = 0; i < modelsArray.GetCount(); i++)
	{
		int index = comboModels.AddString(modelsArray.GetAt(i)->modelName);
		comboModels.SetItemData(index, modelsArray.GetAt(i)->ID);
	}

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		CString strModelName;
		for (int i = 0; i < modelsArray.GetCount(); i++)
			if (productType.modelID == modelsArray.GetAt(i)->ID)
			{
				strModelName.Format(_T("%s"), modelsArray.GetAt(i)->modelName);
				int index = comboModels.SelectString(0, strModelName);
				comboModels.SetCurSel(index);

				break;
			}
	}
}

void ProductsDialog::FillComboBoxCategories()
{
	for (int i = 0; i < categoriesArray.GetCount(); i++)
	{
		int index = comboCategories.AddString(categoriesArray.GetAt(i)->categoryName);
		comboCategories.SetItemData(index, categoriesArray.GetAt(i)->ID);
	}

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		CString strCategoryName;
		for (int i = 0; i < categoriesArray.GetCount(); i++)
			if (productType.categoryID == categoriesArray.GetAt(i)->ID)
			{
				strCategoryName.Format(_T("%s"), categoriesArray.GetAt(i)->categoryName);
				int index = comboCategories.SelectString(0, strCategoryName);
				comboCategories.SetCurSel(index);

				break;
			}
	}
}

void ProductsDialog::FillComboBoxRacks()
{
	for (int i = 0; i < racksArray.GetCount(); i++)
	{
		int index = comboRacks.AddString(racksArray.GetAt(i)->rackName);
		comboRacks.SetItemData(index, racksArray.GetAt(i)->ID);
	}

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		CString strRackName;
		for (int i = 0; i < racksArray.GetCount(); i++)
			if (openProduct.rackID == racksArray.GetAt(i)->ID)
			{
				strRackName.Format(_T("%s"), racksArray.GetAt(i)->rackName);
				int index = comboRacks.SelectString(0, strRackName);
				comboRacks.SetCurSel(index);

				break;
			}
	}
}

void ProductsDialog::FillComboBoxShelves()
{
	for (int i = 0; i < shelvesArray.GetCount(); i++)
	{
		int index = comboShelves.AddString(shelvesArray.GetAt(i)->shelfName);
		comboShelves.SetItemData(index, shelvesArray.GetAt(i)->ID);
	}

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		CString strShelfName;
		for (int i = 0; i < shelvesArray.GetCount(); i++)
			if (openProduct.shelfID == shelvesArray.GetAt(i)->ID)
			{
				strShelfName.Format(_T("%s"), shelvesArray.GetAt(i)->shelfName);
				int index = comboShelves.SelectString(0, strShelfName);
				comboShelves.SetCurSel(index);

				break;
			}
	}
}


BEGIN_MESSAGE_MAP(ProductsDialog, CDialog)
	ON_BN_CLICKED(IDOK, &ProductsDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ProductsDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// ProductsDialog message handlers
