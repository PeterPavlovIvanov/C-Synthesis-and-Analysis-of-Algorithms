#pragma once
#include "DialogModes.h"
#include "RacksView.h"
// RacksDialog dialog

class RacksDialog : public CDialog
{
	DECLARE_DYNAMIC(RacksDialog)

	// Constructor / Destructor
	// ----------------

public:
	RacksDialog(RACKS& rack, ShelvesArray& shelvesArray, DialogModes dialogMode, CWnd* pParent = NULL);   // standard constructor
	virtual ~RacksDialog(); //virtual destructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RACKS_DIALOG};
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

	void FillListShelves();

	void SetEditControlsCredentials();

private:
	//Members
	// ----------------
private:
	DialogModes dialogMode;

	RACKS& openRack;
	ShelvesArray& shelvesArray;

public:
	CEdit editRackNumber;
	CEdit editRackName;
	CListCtrl listShelves;

	CString dlgCaption;
};