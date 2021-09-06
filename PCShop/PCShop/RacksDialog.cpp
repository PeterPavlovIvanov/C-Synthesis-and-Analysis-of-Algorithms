// RacksDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PCShop.h"
#include "RacksDialog.h"
#include "afxdialogex.h"


// RacksDialog dialog

IMPLEMENT_DYNAMIC(RacksDialog, CDialog)

RacksDialog::RacksDialog(RACKS& rack, ShelvesArray& shelvesArray, DialogModes dialogMode, CWnd* pParent /*=NULL*/)
	: CDialog(IDD_RACKS_DIALOG, pParent), openRack(rack), shelvesArray(shelvesArray)
{
	SetCaption(dialogMode);
}

RacksDialog::~RacksDialog()
{
}

void RacksDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RACK_ID, editRackNumber);
	DDX_Control(pDX, IDC_EDIT_RACKS_RACK_NAME, editRackName);
	DDX_Control(pDX, IDC_LIST_RACKS_SHELVES, listShelves);
}


BEGIN_MESSAGE_MAP(RacksDialog, CDialog)
	ON_BN_CLICKED(IDOK, &RacksDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &RacksDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// RacksDialog message handlers
void RacksDialog::OnBnClickedOk()
{
	if (DialogToBuf() != TRUE)
		return;
	CDialog::OnOK();
}

void RacksDialog::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

BOOL RacksDialog::DialogToBuf()
{
	CString strWindowText;
	CString message; //error message
	BOOL bResult = TRUE;

	//rack name
	editRackName.GetWindowText(strWindowText);
	wcscpy_s(openRack.rackName, strWindowText);

	//rack ID
	if (dialogMode == DialogModes::DialogModeInsert)
		openRack.ID = 0;

	if (bResult != TRUE)
	{
		AfxMessageBox(message);
		return FALSE;
	}

	return TRUE;
}

BOOL RacksDialog::OnInitDialog()
{
	__super::OnInitDialog();

	SetWindowText(dlgCaption);

	FillListShelves();

	SetEditControlsCredentials();

	return TRUE;
}

void RacksDialog::SetCaption(DialogModes dialogModeToSet)
{
	switch (dialogModeToSet)
	{
	case DialogModeUpdate:
		dlgCaption = _T("Update Rack");
		break;
	case DialogModeDelete:
		dlgCaption = _T("Are you sure you want to delete this Rack?");
		break;
	case DialogModePreview:
		dlgCaption = _T("Preview Rack");
		break;
	case DialogModeInsert:
		dlgCaption = _T("Add Rack");
		break;
	};

	this->dialogMode = dialogModeToSet;
}

void RacksDialog::FillListShelves()
{
	listShelves.SetView(LVS_REPORT);
	//todo: LVS_SINGLESEL
	listShelves.SetExtendedStyle(listShelves.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	listShelves.InsertColumn(0, _T(""), LVCFMT_RIGHT);
	listShelves.InsertColumn(1, _T("SHELF_NAME"), LVCFMT_RIGHT, COLUMN_WIDTH_SMALL - 13);
	listShelves.InsertColumn(2, _T("CAPACITY"), LVCFMT_RIGHT, COLUMN_WIDTH_TINY - 2);
	listShelves.InsertColumn(3, _T("SPACE_TAKEN"), LVCFMT_RIGHT, COLUMN_WIDTH_SMALL - 7);
	listShelves.InsertColumn(4, _T("PRODUCTS_COUNT"), LVCFMT_RIGHT, COLUMN_WIDTH_BASIC - 13);

	for (int i = 0; i < shelvesArray.GetCount(); i++)
	{
		SHELVES* shelf = shelvesArray.GetAt(i);
		CString strCapacity, strSpaceTaken, strProductsCount;
		strCapacity.Format(_T("%d"), shelf->capacity);
		strSpaceTaken.Format(_T("%d"), shelf->spaceTaken);
		strProductsCount.Format(_T("%d"), shelf->productCount);

		int index = listShelves.InsertItem(0, shelf->shelfName);
		listShelves.SetItemText(index, 1, shelf->shelfName);
		listShelves.SetItemText(index, 2, strCapacity);
		listShelves.SetItemText(index, 3, strSpaceTaken);
		listShelves.SetItemText(index, 4, strProductsCount);
	}

	listShelves.DeleteColumn(0);
}

void RacksDialog::SetEditControlsCredentials()
{
	CString strCapacity, strSpaceTaken, strProductsCount, strRackID;

	if (dialogMode != DialogModes::DialogModeInsert)
	{
		for (int i = 0; i < shelvesArray.GetCount(); i++)
		{
			strCapacity.Format(_T("%d"), shelvesArray.GetAt(i)->capacity);
			strSpaceTaken.Format(_T("%d"), shelvesArray.GetAt(i)->spaceTaken);
			strProductsCount.Format(_T("%d"), shelvesArray.GetAt(i)->productCount);

			int index = listShelves.InsertItem(0, shelvesArray.GetAt(i)->shelfName);
			listShelves.SetItemText(index, 1, strCapacity);
			listShelves.SetItemText(index, 2, strSpaceTaken);
			listShelves.SetItemText(index, 3, strProductsCount);
		}
	}
	strRackID.Format(_T("%d"), openRack.ID);

	SetDlgItemText(IDC_EDIT_RACK_ID, strRackID);
	SetDlgItemText(IDC_EDIT_RACKS_RACK_NAME, openRack.rackName);

	editRackNumber.SetReadOnly();

	if (dialogMode == DialogModes::DialogModePreview || dialogMode == DialogModes::DialogModeDelete)
	{
		editRackName.SetReadOnly();
	}

	if (dialogMode == DialogModes::DialogModeInsert)
	{
		editRackNumber.SetWindowText(_T("Assigns automatically."));
	}
}