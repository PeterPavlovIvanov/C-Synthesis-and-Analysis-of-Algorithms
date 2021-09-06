#pragma once
#include "DialogModes.h"
#include "CategoriesView.h"

// CategoriesDialog dialog

class CategoriesDialog : public CDialog
{
	DECLARE_DYNAMIC(CategoriesDialog)

public:
	CategoriesDialog(CATEGORIES& category, DialogModes dialogMode, CWnd* pParent = NULL);   // standard constructor
	virtual ~CategoriesDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CATEGORIES };
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

private:
	//Members
	// ----------------
private:
	DialogModes dialogMode;

	CATEGORIES& openCategory;

public:
	CEdit editCategoryName;

	CString dlgCaption;
};
