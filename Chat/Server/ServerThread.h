#pragma once

#include "Thread.h"

class ServerThread : public Thread
{
private:
	HWND m_hMainWnd;
public:
	ServerThread(HWND m_hMainWnd);
	~ServerThread();
private:
	BOOL OnInit();
	int Run();
	void OnExit();
};

