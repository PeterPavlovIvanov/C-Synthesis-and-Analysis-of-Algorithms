#pragma once
#include "DialogModes.h"
#include "BrandsView.h"

// BrandsDialog dialog

class BrandsDialog : public CDialog
{
	DECLARE_DYNAMIC(BrandsDialog)

public:
	BrandsDialog(BRANDS& brand, ModelsArray& modelsArray, DialogModes dialogMode, CWnd* pParent = NULL);   // standard constructor
	virtual ~BrandsDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BRANDS };
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

	void FillListModels();

	void SetEditControlsCredentials();

private:
	//Members
	// ----------------
private:
	DialogModes dialogMode;

	BRANDS& openBrand;
	ModelsArray& modelsArray;

public:
	CEdit editBrandName;
	CListCtrl listModels;

	CString dlgCaption;
};