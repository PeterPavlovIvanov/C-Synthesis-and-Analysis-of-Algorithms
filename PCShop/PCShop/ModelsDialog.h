#pragma once
#include "DialogModes.h"
#include "ModelsView.h"

// ModelsDialog dialog

class ModelsDialog : public CDialog
{
	DECLARE_DYNAMIC(ModelsDialog)

public:
	ModelsDialog(MODELS& model, BRANDS& brand, DialogModes dialogMode, CWnd* pParent = NULL);   // standard constructor
	virtual ~ModelsDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MODELS };
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

	MODELS& openModel;
	BRANDS& brand;

public:
	CEdit editModelName;
	CEdit editBrandName;

	CString dlgCaption;
};
