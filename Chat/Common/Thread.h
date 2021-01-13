#pragma once

#include <Windows.h>

class Thread
{
	friend DWORD WINAPI InternalThreadProc(_In_ LPVOID lpParam);
//Properties
public:
protected:
	HANDLE m_hThread;
	DWORD m_dwThreadId;
	DWORD m_dwExitCode;
private:
//Methods
public:
	Thread();
	virtual ~Thread();
	//Getters
	HANDLE getHandle() const { return m_hThread; }
	HANDLE getHandle() { return m_hThread; }
	DWORD getId() { return m_dwThreadId; }
	DWORD getId() const { return m_dwThreadId; }
	DWORD getExitCode() { return m_dwExitCode; }
	DWORD getExitCode() const { return m_dwExitCode; }
	//Setters
	//Virtuals
	//Others
	BOOL Create(BOOL bSuspended = FALSE);
	BOOL Suspend();
	BOOL Resume();
	BOOL Terminate(DWORD iExitCode);
protected:
	//Virtuals
	virtual BOOL OnInit() { return TRUE; }
	virtual int Run() { return 0; }
	virtual void OnExit() { ; }
	//Others
private:
};

