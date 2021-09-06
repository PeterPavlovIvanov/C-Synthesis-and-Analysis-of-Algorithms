// CategoriesDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "CategoriesDialog.h"
#include "afxdialogex.h"


// CategoriesDialog dialog

IMPLEMENT_DYNAMIC(CategoriesDialog, CDialog)

CategoriesDialog::CategoriesDialog(CATEGORIES& category, DialogModes dialogMode, CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_CATEGORIES, pParent), openCategory(category), dialogMode(dialogMode)
{
	SetCaption(dialogMode);
}

CategoriesDialog::~CategoriesDialog()
{
}

BEGIN_MESSAGE_MAP(CategoriesDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CategoriesDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CategoriesDialog::OnBnClickedCancel)
END_MESSAGE_MAP()

void CategoriesDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CATEGORIES_CATEGORY_NAME, editCategoryName);
}

void CategoriesDialog::OnBnClickedOk()
{
	if (DialogToBuf() != TRUE)
		return;
	CDialog::OnOK();
}

void CategoriesDialog::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

BOOL CategoriesDialog::DialogToBuf()
{
	CString strWindowText;

	//category name
	editCategoryName.GetWindowText(strWindowText);
	wcscpy_s(openCategory.categoryName, strWindowText);

	return TRUE;
}

BOOL CategoriesDialog::OnInitDialog()
{
	__super::OnInitDialog();

	SetWindowText(dlgCaption);

	SetEditControlsCredentials();

	return TRUE;
}

void CategoriesDialog::SetCaption(DialogModes dialogModeToSet)
{
	switch (dialogModeToSet)
	{
	case DialogModeUpdate:
		dlgCaption = _T("Update Category");
		break;
	case DialogModeDelete:
		dlgCaption = _T("Are you sure you want to delete this Category?");
		break;
	case DialogModePreview:
		dlgCaption = _T("Preview Category");
		break;
	case DialogModeInsert:
		dlgCaption = _T("Add Category");
		break;
	};

	this->dialogMode = dialogModeToSet;
}

void CategoriesDialog::SetEditControlsCredentials()
{
	SetDlgItemText(IDC_EDIT_CATEGORIES_CATEGORY_NAME, openCategory.categoryName);

	if (dialogMode == DialogModes::DialogModePreview || dialogMode == DialogModes::DialogModeDelete)
	{
		editCategoryName.SetReadOnly();
	}
}



// CategoriesDialog message handlers
