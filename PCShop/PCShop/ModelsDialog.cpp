// ModelsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ModelsDialog.h"
#include "afxdialogex.h"


// ModelsDialog dialog

IMPLEMENT_DYNAMIC(ModelsDialog, CDialog)

ModelsDialog::ModelsDialog(MODELS& model, BRANDS& brand, DialogModes dialogMode, CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_MODELS, pParent), openModel(model), dialogMode(dialogMode), brand(brand)
{
	SetCaption(dialogMode);
}

ModelsDialog::~ModelsDialog()
{
}

void ModelsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);	
	DDX_Control(pDX, IDC_EDIT_MODELS_NAME, editModelName);
	DDX_Control(pDX, IDC_EDIT_MODELS_BRAND, editBrandName);
}

void ModelsDialog::OnBnClickedOk()
{
	if (DialogToBuf() != TRUE)
		return;
	CDialog::OnOK();
}

void ModelsDialog::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

BOOL ModelsDialog::DialogToBuf()
{
	CString strWindowText;

	editModelName.GetWindowText(strWindowText);
	wcscpy_s(openModel.modelName, strWindowText);

	editBrandName.GetWindowText(strWindowText);
	wcscpy_s(brand.brandName, strWindowText);

	return TRUE;
}

BOOL ModelsDialog::OnInitDialog()
{
	__super::OnInitDialog();

	SetWindowText(dlgCaption);

	SetEditControlsCredentials();

	return TRUE;
}

void ModelsDialog::SetCaption(DialogModes dialogModeToSet)
{
	switch (dialogModeToSet)
	{
	case DialogModeUpdate:
		dlgCaption = _T("Update Model");
		break;
	case DialogModeDelete:
		dlgCaption = _T("Are you sure you want to delete this Model?");
		break;
	case DialogModePreview:
		dlgCaption = _T("Preview Model");
		break;
	case DialogModeInsert:
		dlgCaption = _T("Add Model");
		break;
	};

	this->dialogMode = dialogModeToSet;
}

void ModelsDialog::SetEditControlsCredentials()
{
	SetDlgItemText(IDC_EDIT_MODELS_NAME, openModel.modelName);
	SetDlgItemText(IDC_EDIT_MODELS_BRAND, brand.brandName);

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		editBrandName.SetReadOnly();
	}

	if (dialogMode == DialogModes::DialogModePreview || dialogMode == DialogModes::DialogModeDelete)
	{
		editModelName.SetReadOnly();
	}
}


BEGIN_MESSAGE_MAP(ModelsDialog, CDialog)
	ON_BN_CLICKED(IDOK, &ModelsDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ModelsDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// ModelsDialog message handlers
