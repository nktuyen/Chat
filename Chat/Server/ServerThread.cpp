#include "pch.h"
#include "ServerThread.h"

ServerThread::ServerThread(HWND hMainWnd)
{
	m_hMainWnd = hMainWnd;
}

ServerThread::~ServerThread()
{

}

BOOL ServerThread::OnInit()
{
	if (NULL != m_hMainWnd)
	{
		::SetWindowText(m_hMainWnd, _T("Initializing..."));
	}
	return TRUE;
}

int ServerThread::Run()
{
	int count = 100;
	TCHAR sz[255] = { 0 };
	while (count>0)
	{
		Sleep(100);
		if (NULL != m_hMainWnd)
		{
			wsprintf(sz, _T("%d"), count--);
			::SetWindowText(m_hMainWnd, sz);
		}
	}

	return 999;
}

void ServerThread::OnExit()
{
	if (NULL != m_hMainWnd)
	{
		::SetWindowText(m_hMainWnd, _T("Finalizing..."));
	}
}