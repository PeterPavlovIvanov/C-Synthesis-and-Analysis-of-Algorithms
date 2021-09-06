// BrandsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "BrandsDialog.h"
#include "afxdialogex.h"


// BrandsDialog dialog

IMPLEMENT_DYNAMIC(BrandsDialog, CDialog)

BrandsDialog::BrandsDialog(BRANDS& brand, ModelsArray& modelsArray, DialogModes dialogMode, CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_BRANDS, pParent), openBrand(brand), modelsArray(modelsArray)
{
	SetCaption(dialogMode);
}

BrandsDialog::~BrandsDialog()
{
}

void BrandsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_BRANDS_NAME, editBrandName);
	DDX_Control(pDX, IDC_LIST_BRANDS_MODELS, listModels);
}

void BrandsDialog::OnBnClickedOk()
{
	if (DialogToBuf() != TRUE)
		return;
	CDialog::OnOK();
}

void BrandsDialog::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

BOOL BrandsDialog::DialogToBuf()
{
	CString strWindowText;

	//rack name
	editBrandName.GetWindowText(strWindowText);
	wcscpy_s(openBrand.brandName, strWindowText);

	return TRUE;
}

BOOL BrandsDialog::OnInitDialog()
{
	__super::OnInitDialog();

	SetWindowText(dlgCaption);

	FillListModels();

	SetEditControlsCredentials();

	return TRUE;
}

void BrandsDialog::SetCaption(DialogModes dialogModeToSet)
{
	switch (dialogModeToSet)
	{
	case DialogModeUpdate:
		dlgCaption = _T("Update Brand");
		break;
	case DialogModeDelete:
		dlgCaption = _T("Are you sure you want to delete this Brand?");
		break;
	case DialogModePreview:
		dlgCaption = _T("Preview Brand");
		break;
	case DialogModeInsert:
		dlgCaption = _T("Add Brand");
		break;
	};

	this->dialogMode = dialogModeToSet;
}

void BrandsDialog::FillListModels()
{
	listModels.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listModels.SetExtendedStyle(listModels.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listModels.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listModels.InsertColumn(1, _T("Model name"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC - 13);

	for (int i = 0; i < modelsArray.GetCount(); i++)
	{
		MODELS* model = modelsArray.GetAt(i);

		int index = listModels.InsertItem(0, model->modelName);
		listModels.SetItemText(index, 1, model->modelName);
	}

	listModels.DeleteColumn(0);
}

void BrandsDialog::SetEditControlsCredentials()
{
	if (dialogMode != DialogModes::DialogModeInsert)
	{
		for (int i = 0; i < modelsArray.GetCount(); i++)
		{
			int index = listModels.InsertItem(0, modelsArray.GetAt(i)->modelName);
		}
	}

	SetDlgItemText(IDC_EDIT_BRANDS_NAME, openBrand.brandName);

	if (dialogMode == DialogModes::DialogModePreview || dialogMode == DialogModes::DialogModeDelete)
	{
		editBrandName.SetReadOnly();
	}
}


BEGIN_MESSAGE_MAP(BrandsDialog, CDialog)
	ON_BN_CLICKED(IDOK, &BrandsDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &BrandsDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// BrandsDialog message handlers
