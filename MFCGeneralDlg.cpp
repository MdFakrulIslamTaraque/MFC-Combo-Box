
// MFCGeneralDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCGeneral.h"
#include "MFCGeneralDlg.h"
#include "afxdialogex.h"
#include<iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCGeneralDlg dialog



CMFCGeneralDlg::CMFCGeneralDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCGENERAL_DIALOG, pParent)
	, m_last_selected(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCGeneralDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Left, m_combo_left);
	DDX_Control(pDX, IDC_COMBO_Middle, m_combo_middle);
	DDX_Control(pDX, IDC_COMBO_Right, m_combo_right);
	DDX_Text(pDX, IDC_EDIT_last_selected, m_last_selected);
	DDX_Control(pDX, IDC_EDIT_left_add_value, m_add_left);
	DDX_Control(pDX, IDC_EDIT_add_Middle, m_add_middle);
	DDX_Control(pDX, IDC_EDIT_Add_Right, m_add_right);
}

BEGIN_MESSAGE_MAP(CMFCGeneralDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO_Left, &CMFCGeneralDlg::OnCbnSelchangeComboLeft)
	ON_CBN_SELCHANGE(IDC_COMBO_Middle, &CMFCGeneralDlg::OnCbnSelchangeComboMiddle)
	ON_CBN_SELCHANGE(IDC_COMBO_Right, &CMFCGeneralDlg::OnCbnSelchangeComboRight)
	ON_BN_CLICKED(IDC_BUTTON_add_left, &CMFCGeneralDlg::OnBnClickedButtonaddleft)
	ON_BN_CLICKED(IDC_BUTTON_Add_Middle, &CMFCGeneralDlg::OnBnClickedButtonAddMiddle)
	ON_BN_CLICKED(IDC_BUTTON_Add_Right, &CMFCGeneralDlg::OnBnClickedButtonAddRight)
END_MESSAGE_MAP()


// CMFCGeneralDlg message handlers

BOOL CMFCGeneralDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization her

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCGeneralDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCGeneralDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCGeneralDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMFCGeneralDlg::OnCbnSelchangeComboLeft()
{
	int cBox1Item = m_combo_left.GetCurSel();
	if (cBox1Item != LB_ERR)
	{
		m_combo_left.GetLBText(cBox1Item, m_last_selected);
		m_last_selected = _T("From left: ") + m_last_selected;
		UpdateData(FALSE);
	}
}


void CMFCGeneralDlg::OnCbnSelchangeComboMiddle()
{
	int cBox2Item = m_combo_middle.GetCurSel();
	if(cBox2Item != LB_ERR)
	{
		m_combo_middle.GetLBText(cBox2Item, m_last_selected);
		m_last_selected = _T("From middle: ") + m_last_selected;
		UpdateData(FALSE);
	}
}


void CMFCGeneralDlg::OnCbnSelchangeComboRight()
{
	int cBox3Item = m_combo_right.GetCurSel();
	if (cBox3Item != LB_ERR)
	{
		m_combo_right.GetLBText(cBox3Item, m_last_selected);
		m_last_selected = _T("From right: ") + m_last_selected;
		UpdateData(FALSE);
	}
}


void CMFCGeneralDlg::OnBnClickedButtonaddleft()
{
	CString addStrLeft;
	m_add_left.GetWindowText(addStrLeft);
	m_combo_left.AddString(addStrLeft);
}


void CMFCGeneralDlg::OnBnClickedButtonAddMiddle()
{
	CString addStrMiddle;
	m_add_middle.GetWindowText(addStrMiddle);
	m_combo_middle.AddString(addStrMiddle);
}


void CMFCGeneralDlg::OnBnClickedButtonAddRight()
{
	CString addStrRight;
	m_add_right.GetWindowText(addStrRight);
	m_combo_right.AddString(addStrRight);
}
