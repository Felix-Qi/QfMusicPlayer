//file name: Play.h
//function: header file of Play.cpp
#include <VFW.H>

#define    MAX_NAME_LENTH    100




class CPlayer
{
public:
	CPlayer()
	{
		memset(m_achPathName, 0, sizeof(m_achPathName));
		m_hAudio = NULL;
		m_nState = STATE_UNPLAY;
	}
	~CPlayer()
	{

	}
public:
	bool SetFilePathName(char *pPathName);
	bool SetAudioHandler(HWND hWnd);
	bool play(void);
	bool pause(void);
	//bool stop(void);
protected:
private:
	char m_achPathName[MAX_NAME_LENTH + 1];
	HWND m_hAudio;
	int  m_nState;
	typedef enum
	{
		STATE_UNPLAY,
		STATE_PLAY,
		STATE_PAUSED
	};
};

//typedef class CPlayer TCPlayer;


