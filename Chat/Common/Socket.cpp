#include "pch.h"
#include "Socket.h"

Socket::Socket(int af, int type, int proto)
{
	m_sock = INVALID_SOCKET;
	m_iAddressFamily = af;
	m_iType = type;
	m_iProtocol = proto;
}

Socket::~Socket()
{
	if (INVALID_SOCKET != m_sock)
	{
		::closesocket(m_sock);
		m_sock = INVALID_SOCKET;
	}
}

BOOL Socket::Create()
{
	m_sock = ::socket(m_iAddressFamily, m_iType, m_iProtocol);
	if (INVALID_SOCKET != m_sock)
	{
		return TRUE;
	}

	return FALSE;
}

void Socket::Close()
{
	int res = ::closesocket(m_sock);
}