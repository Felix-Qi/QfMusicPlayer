// QFplayerDlg.cpp : implementation file
//
#include <vfw.h>
#include "stdafx.h"
#include "QFplayer.h"
#include "QFplayerDlg.h"
#include "Play.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CPlayer cPlayer;

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQFplayerDlg dialog

CQFplayerDlg::CQFplayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQFplayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQFplayerDlg)
	m_strName = _T("");
	m_strTotalTime = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQFplayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQFplayerDlg)
	DDX_Control(pDX, IDC_PROGRESS1, m_PrgsBar);
	DDX_Text(pDX, IDC_MUSIC_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 100);
	DDX_Text(pDX, IDC_TOTAL_TIME, m_strTotalTime);
	DDV_MaxChars(pDX, m_strTotalTime, 10);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CQFplayerDlg, CDialog)
	//{{AFX_MSG_MAP(CQFplayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_PLAY, OnPlay)
	ON_BN_CLICKED(ID_SELECT, OnSelect)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQFplayerDlg message handlers

BOOL CQFplayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	// TODO: Add extra initialization here
	m_nTimeLenth = 0;
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CQFplayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CQFplayerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CQFplayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CQFplayerDlg::OnPlay() 
{
	// TODO: Add your control notification handler code here
		
	if (!m_bIsPlay)
	{
		cPlayer.play();
		m_bIsPlay = TRUE;		
		SetDlgItemText(ID_PLAY, "暂停");
		SetTimer(1234, 1000, NULL);
		//m_nCurTime = 0;
	} 
	else
	{
		cPlayer.pause();
		m_bIsPlay = FALSE;		
		SetDlgItemText(ID_PLAY, "播放");
	}		
}


void CQFplayerDlg::OnSelect() 
{
	// TODO: Add your control notification handler code here
	//打开选择文件窗口
	CString strFilter="所有支持文件(*.mp3,*.wav,*.wma)|*.mp3;*.wav;*.wma||";
	CFileDialog fileDlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,strFilter);
	
	//如果已正常打开
	if (IDOK == fileDlg.DoModal()) 
	{  
		CFile file(fileDlg.GetFileName(),CFile::modeRead);  		
		
		m_strName = fileDlg.GetPathName();//文件名+后缀  
		UpdateData(FALSE);  //变量更新控件
		char achName[MAX_NAME_LENTH + 1];
		memset(achName, 0, MAX_NAME_LENTH + 1);
		strncpy(achName, m_strName, m_strName.GetLength());
		//传输
		cPlayer.SetFilePathName(achName);		
	} 
	//创建
	HWND hAudio = MCIWndCreate(GetSafeHwnd(),AfxGetInstanceHandle(),
		WS_CHILD|MCIWNDF_NOMENU,m_strName);
	if (hAudio != NULL)
	{
		cPlayer.SetAudioHandler(hAudio);
		m_bIsPlay = FALSE;
	}
	else
	{
		MessageBox("创建MCI失败！");
	}
	//计算总时长
	if (hAudio != NULL)
	{
		m_nTimeLenth = MCIWndGetLength(hAudio) / MCIWndGetSpeed(hAudio);
		//设置进度条范围
		m_PrgsBar.SetRange(0, m_nTimeLenth);
		m_PrgsBar.SetPos(0);
		m_nCurTime = 0;
		int nMinute = m_nTimeLenth / 60;
		int nSecond = m_nTimeLenth % 60;
		if (nMinute < 10)
		{
			if(nSecond<10)
				m_strTotalTime.Format("0%d:0%d",nMinute,nSecond);
			else
				m_strTotalTime.Format("0%d:%d",nMinute,nSecond);
		}
		else
		{
			if(nSecond<10)
				m_strTotalTime.Format("%d:0%d",nMinute,nSecond);
			else
				m_strTotalTime.Format("%d:%d",nMinute,nSecond);
		}
		UpdateData(FALSE);  //变量更新控件
	}
}

void CQFplayerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_bIsPlay)
	{
		m_PrgsBar.SetPos(++m_nCurTime);
	}
	
	CDialog::OnTimer(nIDEvent);
}
