// QFplayer.h : main header file for the QFPLAYER application
//

#if !defined(AFX_QFPLAYER_H__2CDA706E_8A92_4652_AF6A_F479EE6262A1__INCLUDED_)
#define AFX_QFPLAYER_H__2CDA706E_8A92_4652_AF6A_F479EE6262A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CQFplayerApp:
// See QFplayer.cpp for the implementation of this class
//

class CQFplayerApp : public CWinApp
{
public:
	CQFplayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQFplayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CQFplayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QFPLAYER_H__2CDA706E_8A92_4652_AF6A_F479EE6262A1__INCLUDED_)
