
// MFCGeneralDlg.h : header file
//

#pragma once


// CMFCGeneralDlg dialog
class CMFCGeneralDlg : public CDialogEx
{
// Construction
public:
	CMFCGeneralDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCGENERAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_left;
	CComboBox m_combo_middle;
	CComboBox m_combo_right;
	afx_msg void OnCbnSelchangeComboLeft();
	afx_msg void OnCbnSelchangeComboMiddle();
	afx_msg void OnCbnSelchangeComboRight();
	CString m_last_selected;
	CEdit m_add_left;
	afx_msg void OnBnClickedButtonaddleft();
	CEdit m_add_middle;
	afx_msg void OnBnClickedButtonAddMiddle();
	CEdit m_add_right;
	afx_msg void OnBnClickedButtonAddRight();
};
