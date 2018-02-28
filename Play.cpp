//file name: Play.cpp
//function: baic function to play music


#include "stdafx.h"//������ǰ
#include "Play.h"
#include <VFW.H>
#include <afxwin.h>
#include <AFXWIN2.INL>



CPlayer cPlayer;



//�����ļ�·�����ļ���
bool CPlayer::SetFilePathName(char *pPathName)
{
	strcpy(m_achPathName, pPathName);

	return TRUE;
}


bool CPlayer::SetAudioHandler(HWND hWnd)
{
	if (hWnd != NULL)
	{
		m_hAudio = hWnd;	
		return TRUE;
	} 
	else
	{
		return FALSE;
	}	
}


//��������
bool CPlayer::play(void)
{
	//m_hAudio = MCIWndCreate(GetSafeHwnd(),AfxGetInstanceHandle(),
	//	           WS_CHILD|MCIWNDF_NOMENU, m_achPathName);
	if (m_hAudio != NULL)
	{
		if (STATE_UNPLAY == m_nState)
		{
			MCIWndPlay(m_hAudio);
		}
		else if (STATE_PAUSED == m_nState)
		{
			MCIWndResume(m_hAudio);
		}
		m_nState = STATE_PLAY;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}




//��ͣ����
bool CPlayer::pause(void)
{
	if (m_hAudio != NULL)
	{
		if (STATE_PLAY == m_nState)
		{
			MCIWndPause(m_hAudio);
			m_nState = STATE_PAUSED;
		}	
		return TRUE;
	}
	else
	{
		return FALSE;
	}	
}




//ֹͣ����
/*bool CPlayer::stop(void)
{
	if (m_hAudio != NULL)
	{
		if (STATE_PLAY == m_nState)
		{
			MCIWndStop(m_hAudio);
			m_nState = STATE_UNPLAY;
		}		
	}
	
	return TRUE;
}*/
