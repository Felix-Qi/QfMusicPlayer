; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CQFplayerDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "QFplayer.h"

ClassCount=3
Class1=CQFplayerApp
Class2=CQFplayerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_QFPLAYER_DIALOG

[CLS:CQFplayerApp]
Type=0
HeaderFile=QFplayer.h
ImplementationFile=QFplayer.cpp
Filter=N

[CLS:CQFplayerDlg]
Type=0
HeaderFile=QFplayerDlg.h
ImplementationFile=QFplayerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_PROGRESS1

[CLS:CAboutDlg]
Type=0
HeaderFile=QFplayerDlg.h
ImplementationFile=QFplayerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_QFPLAYER_DIALOG]
Type=1
Class=CQFplayerDlg
ControlCount=5
Control1=ID_PLAY,button,1342242817
Control2=ID_SELECT,button,1342242816
Control3=IDC_MUSIC_NAME,static,1342308352
Control4=IDC_PROGRESS1,msctls_progress32,1350565888
Control5=IDC_TOTAL_TIME,static,1342308352

