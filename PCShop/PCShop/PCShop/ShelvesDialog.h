#pragma once
#include "DialogModes.h"
#include "ShelvesView.h"

// ShelvesDialog dialog

class ShelvesDialog : public CDialog
{
	DECLARE_DYNAMIC(ShelvesDialog)

	// Constructor / Destructor
	// ----------------
public:
	///<summary>Standard-ен конструктор</summary>
	ShelvesDialog(SHELVES& shelf, RacksArray& racksArray, DialogModes dialogMode, CWnd* pParent = NULL);

	///<summary>Виртуален Деструктор<summary>
	virtual ~ShelvesDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHELVES_DIALOG };
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

	void FillComboBoxRacks();

	void SetEditControlsCredentials();

private:
	void ValidateStringOnlyLetters(CString strWindowText, CString& message, BOOL& bResult, CString strFieldName);

	//Members
	// ----------------
private:
	DialogModes dialogMode;

	SHELVES& openShelf;
	RacksArray& racksArray;

public:
	CEdit editShelfNumber;
	CEdit editShelfName;
	CEdit editShelfCapacity;
	CEdit editShelfSpaceTaken;
	CComboBox comboShelfsRack;
	CEdit editShelfProductsCount;

	CString dlgCaption;
};