// QFplayerDlg.h : header file
//

#if !defined(AFX_QFPLAYERDLG_H__4E5FFB46_6AC5_4857_A11F_861126FE3CC9__INCLUDED_)
#define AFX_QFPLAYERDLG_H__4E5FFB46_6AC5_4857_A11F_861126FE3CC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CQFplayerDlg dialog

class CQFplayerDlg : public CDialog
{
// Construction
public:
	CQFplayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CQFplayerDlg)
	enum { IDD = IDD_QFPLAYER_DIALOG };
	CProgressCtrl	m_PrgsBar;
	CString	m_strName;
	CString	m_strTotalTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQFplayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CQFplayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnPlay();
	afx_msg void OnSelect();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	BOOL m_bIsPlay;
	int  m_nTimeLenth;
	int  m_nCurTime;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QFPLAYERDLG_H__4E5FFB46_6AC5_4857_A11F_861126FE3CC9__INCLUDED_)
