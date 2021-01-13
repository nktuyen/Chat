#include "pch.h"
#include "Thread.h"

Thread::Thread()
{
	m_hThread = INVALID_HANDLE_VALUE;
	m_dwExitCode = 0;
	m_dwThreadId = 0;
}

Thread::~Thread()
{
	if (INVALID_HANDLE_VALUE != m_hThread)
	{
		::CloseHandle(m_hThread);
		m_hThread = INVALID_HANDLE_VALUE;
	}
}

DWORD WINAPI InternalThreadProc(_In_ LPVOID lpParam)
{
	if (NULL == lpParam)
	{
		return 0;
	}

	Thread* pThread = (Thread*)lpParam;

	if (!pThread->OnInit())
	{
		return pThread->getExitCode();
	}

	pThread->m_dwExitCode = pThread->Run();
	pThread->OnExit();
	::CloseHandle(pThread->m_hThread);
	pThread->m_hThread = INVALID_HANDLE_VALUE;

	return pThread->m_dwExitCode;
}

BOOL Thread::Create(BOOL bSuspended)
{
	m_hThread = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)InternalThreadProc, this, bSuspended ? CREATE_SUSPENDED : 0, &m_dwThreadId);

	if (INVALID_HANDLE_VALUE != m_hThread)
	{
		return TRUE;
	}

	return FALSE;
}

BOOL Thread::Suspend()
{
	return ::SuspendThread(m_hThread);
}

BOOL Thread::Resume()
{
	return ::ResumeThread(m_hThread);
}

BOOL Thread::Terminate(DWORD dwExitCode)
{
	return ::TerminateThread(m_hThread, dwExitCode);
}