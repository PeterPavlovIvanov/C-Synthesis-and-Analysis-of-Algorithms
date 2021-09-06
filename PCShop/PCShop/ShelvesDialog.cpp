// ShelvesDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "ShelvesDialog.h"
#include "afxdialogex.h"


// ShelvesDialog dialog

IMPLEMENT_DYNAMIC(ShelvesDialog, CDialog)

ShelvesDialog::ShelvesDialog(SHELVES & shelf, RacksArray & racksArray, DialogModes dialogMode, CWnd * pParent /*=NULL*/)
	: CDialog(IDD_SHELVES_DIALOG, pParent), openShelf(shelf), racksArray(racksArray)
{
	SetCaption(dialogMode);
}

ShelvesDialog::~ShelvesDialog()
{
}

void ShelvesDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SHELF_NUMBER, editShelfNumber);
	DDX_Control(pDX, IDC_EDIT_SHELF_NAME, editShelfName);
	DDX_Control(pDX, IDC_EDIT_SHELF_PRODUCT_COUNT, editShelfProductsCount);
	DDX_Control(pDX, IDC_EDIT_SHELF_SPACE_TAKEN, editShelfSpaceTaken);
	DDX_Control(pDX, IDC_EDIT_SHELF_CAPACITY, editShelfCapacity);
	DDX_Control(pDX, IDC_COMBO_SHELFS_RACK, comboShelfsRack);
}

BEGIN_MESSAGE_MAP(ShelvesDialog, CDialog)
	ON_BN_CLICKED(IDOK, &ShelvesDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ShelvesDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// ShelvesDialog message handlers

void ShelvesDialog::OnBnClickedOk()
{
	if (DialogToBuf() != TRUE)
		return;
	CDialog::OnOK();
}

void ShelvesDialog::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

BOOL ShelvesDialog::DialogToBuf()
{
	CString strWindowText;
	CString message; //error message
	BOOL bResult = TRUE;

	//shelf name
	editShelfName.GetWindowText(strWindowText);
	wcscpy_s(openShelf.shelfName, strWindowText);

	//shelf capacity
	editShelfCapacity.GetWindowText(strWindowText);
	openShelf.capacity = _wtol(strWindowText);

	//shelf ID
	if (dialogMode == DialogModes::DialogModeInsert)
		openShelf.ID = 0;

	//shelf productCount
	editShelfProductsCount.GetWindowText(strWindowText);
	openShelf.productCount = _wtol(strWindowText);

	//shelf spaceTaken
	editShelfSpaceTaken.GetWindowText(strWindowText);
	openShelf.spaceTaken = _wtol(strWindowText);

	//shelf's rack
	long index = comboShelfsRack.GetCurSel();
	if (index == CB_ERR)
	{
		message.AppendFormat(_T("\nA rack must be selected."));
		bResult = FALSE;
	}
	openShelf.rackID = (long)comboShelfsRack.GetItemData(index);

	if (bResult != TRUE)
	{
		AfxMessageBox(message);
		return FALSE;
	}

	return TRUE;
}

BOOL ShelvesDialog::OnInitDialog()
{
	__super::OnInitDialog();

	SetWindowText(dlgCaption);

	FillComboBoxRacks();

	SetEditControlsCredentials();

	return TRUE;
}

void ShelvesDialog::SetCaption(DialogModes dialogModeToSet)
{
	switch (dialogModeToSet)
	{
	case DialogModeUpdate:
		dlgCaption = _T("Update Shelf");
		break;
	case DialogModeDelete:
		dlgCaption = _T("Are you sure you want to delete this Shelf?");
		break;
	case DialogModePreview:
		dlgCaption = _T("Preview Shelf");
		break;
	case DialogModeInsert:
		dlgCaption = _T("Add Shelf");
		break;
	};

	this->dialogMode = dialogModeToSet;
}

void ShelvesDialog::FillComboBoxRacks()
{
	for (int i = 0; i < racksArray.GetCount(); i++)
	{
		int index = comboShelfsRack.AddString(racksArray.GetAt(i)->rackName);
		comboShelfsRack.SetItemData(index, racksArray.GetAt(i)->ID);
	}

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		CString stringRackName;
		for (int i = 0; i < racksArray.GetCount(); i++)
			if (openShelf.rackID == racksArray.GetAt(i)->ID)
			{
				stringRackName.Format(_T("%s"), racksArray.GetAt(i)->rackName);
				int index = comboShelfsRack.SelectString(0, stringRackName);
				comboShelfsRack.SetCurSel(index);

				break;
			}
	}
}

void ShelvesDialog::SetEditControlsCredentials()
{
	CString stringID, stringProductCount, stringSpaceTaken, stringCapacity;
	stringID.Format(_T("%d"), openShelf.ID);
	stringCapacity.Format(_T("%d"), openShelf.capacity);
	stringSpaceTaken.Format(_T("%d"), openShelf.spaceTaken);
	stringProductCount.Format(_T("%d"), openShelf.productCount);

	SetDlgItemText(IDC_EDIT_SHELF_NUMBER, stringID);
	SetDlgItemText(IDC_EDIT_SHELF_NAME, openShelf.shelfName);
	SetDlgItemText(IDC_EDIT_SHELF_PRODUCT_COUNT, stringProductCount);
	SetDlgItemText(IDC_EDIT_SHELF_SPACE_TAKEN, stringSpaceTaken);
	SetDlgItemText(IDC_EDIT_SHELF_CAPACITY, stringCapacity);

	if (dialogMode == DialogModes::DialogModePreview || dialogMode == DialogModes::DialogModeDelete)
	{
		editShelfCapacity.SetReadOnly();
		editShelfName.SetReadOnly();
		editShelfNumber.SetReadOnly();
		editShelfProductsCount.SetReadOnly();
		editShelfSpaceTaken.EnableWindow(FALSE);
		comboShelfsRack.EnableWindow(FALSE);
	}

	if (dialogMode == DialogModes::DialogModeInsert)
	{
		editShelfNumber.SetWindowText(_T("Assigns automatically."));
		editShelfNumber.SetReadOnly();
	}
}


