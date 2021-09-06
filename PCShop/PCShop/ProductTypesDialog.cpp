// ProductTypesDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ProductTypesDialog.h"
#include "afxdialogex.h"


// ProductTypesDialog dialog

IMPLEMENT_DYNAMIC(ProductTypesDialog, CDialog)

ProductTypesDialog::ProductTypesDialog(PRODUCT_TYPES & pt, ModelsArray & modelsArray, CategoriesArray & categoriesArray, BrandsArray & brandsArray, DialogModes dialogMode, CWnd * pParent)
	: CDialog(IDD_PRODUCT_TYPES_DIALOG, pParent), categoriesArray(categoriesArray), brandsArray(brandsArray), modelsArray(modelsArray), openProductType(pt)
{
		SetCaption(dialogMode);
}

ProductTypesDialog::~ProductTypesDialog()
{
}

void ProductTypesDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PTS_NAME, editName);
	DDX_Control(pDX, IDC_EDIT_PTS_DESCRIPTION, editDescription);
	DDX_Control(pDX, IDC_EDIT_PTS_PRICE, editPrice);
	DDX_Control(pDX, IDC_EDIT_PTS_QUANTITY, editQuantity);
	DDX_Control(pDX, IDC_EDIT_PTS_SIZE, editSize);
	DDX_Control(pDX, IDC_COMBO_PTS_BRAND, comboBrands);
	DDX_Control(pDX, IDC_COMBO_PTS_CATEGORY, comboCategories);
	DDX_Control(pDX, IDC_COMBO_PTS_MODEL, comboModels);
}

void ProductTypesDialog::OnBnClickedOk()
{
	if (DialogToBuf() != TRUE)
		return;
	CDialog::OnOK();
}

void ProductTypesDialog::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

BOOL ProductTypesDialog::DialogToBuf()
{
	CString strWindowText;
	CString message; //error message
	BOOL bResult = TRUE;

	editName.GetWindowText(strWindowText);
	wcscpy_s(openProductType.productName, strWindowText);

	editDescription.GetWindowText(strWindowText);
	wcscpy_s(openProductType.description, strWindowText);

	editPrice.GetWindowText(strWindowText);
	openProductType.price = _ttof(strWindowText);

	editQuantity.GetWindowText(strWindowText);
	openProductType.quantity = _wtol(strWindowText);

	editSize.GetWindowText(strWindowText);
	openProductType.productSize = _wtol(strWindowText);

	long index = comboBrands.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA brand must be selected."));
		bResult = FALSE;
	}
	openProductType.brandID = (long)comboBrands.GetItemData(index);

	index = comboCategories.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA category must be selected."));
		bResult = FALSE;
	}
	openProductType.categoryID = (long)comboCategories.GetItemData(index);

	index = comboModels.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA model must be selected."));
		bResult = FALSE;
	}
	openProductType.modelID = (long)comboModels.GetItemData(index);

	if (bResult != TRUE)
	{
		AfxMessageBox(message);
		return FALSE;
	}

	return TRUE;
}

BOOL ProductTypesDialog::OnInitDialog()
{
	__super::OnInitDialog();

	SetWindowText(dlgCaption);

	FillComboBoxBrands();
	FillComboBoxCategories();
	FillComboBoxModels();

	SetEditControlsCredentials();

	return TRUE;
}

void ProductTypesDialog::SetCaption(DialogModes dialogModeToSet)
{
	switch (dialogModeToSet)
	{
	case DialogModeUpdate:
		dlgCaption = _T("Update product type");
		break;
	case DialogModeDelete:
		dlgCaption = _T("Are you sure you want to delete this product type?");
		break;
	case DialogModePreview:
		dlgCaption = _T("Preview product type");
		break;
	case DialogModeInsert:
		dlgCaption = _T("Add product type");
		break;
	};

	this->dialogMode = dialogModeToSet;
}

void ProductTypesDialog::SetEditControlsCredentials()
{
	CString stringPrice, stringSize, stringQuantity;
	stringPrice.Format(_T("%.2fd"), openProductType.price);
	stringSize.Format(_T("%d"), openProductType.productSize);
	stringQuantity.Format(_T("%d"), openProductType.quantity);

	SetDlgItemText(IDC_EDIT_PTS_DESCRIPTION, openProductType.description);
	SetDlgItemText(IDC_EDIT_PTS_NAME, openProductType.productName);
	SetDlgItemText(IDC_EDIT_PTS_QUANTITY, stringQuantity);
	SetDlgItemText(IDC_EDIT_PTS_PRICE, stringPrice);
	SetDlgItemText(IDC_EDIT_PTS_SIZE, stringSize);

	if (dialogMode == DialogModes::DialogModePreview || dialogMode == DialogModes::DialogModeDelete)
	{
		editDescription.SetReadOnly();
		editName.SetReadOnly();
		editPrice.SetReadOnly();
		editQuantity.SetReadOnly();
		editSize.SetReadOnly();
		comboBrands.EnableWindow(FALSE);
		comboCategories.EnableWindow(FALSE);
		comboModels.EnableWindow(FALSE);
	}
}

void ProductTypesDialog::FillComboBoxBrands()
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
			if (openProductType.brandID == brandsArray.GetAt(i)->ID)
			{
				strBrandName.Format(_T("%s"), brandsArray.GetAt(i)->brandName);
				int index = comboBrands.SelectString(0, strBrandName);
				comboBrands.SetCurSel(index);

				break;
			}
	}
}

void ProductTypesDialog::FillComboBoxModels()
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
			if (openProductType.modelID == modelsArray.GetAt(i)->ID)
			{
				strModelName.Format(_T("%s"), modelsArray.GetAt(i)->modelName);
				int index = comboModels.SelectString(0, strModelName);
				comboModels.SetCurSel(index);

				break;
			}
	}
}

void ProductTypesDialog::FillComboBoxCategories()
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
			if (openProductType.categoryID == categoriesArray.GetAt(i)->ID)
			{
				strCategoryName.Format(_T("%s"), categoriesArray.GetAt(i)->categoryName);
				int index = comboCategories.SelectString(0, strCategoryName);
				comboCategories.SetCurSel(index);

				break;
			}
	}
}

BEGIN_MESSAGE_MAP(ProductTypesDialog, CDialog)
	ON_BN_CLICKED(IDOK, &ProductTypesDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ProductTypesDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// ProductTypesDialog message handlers
