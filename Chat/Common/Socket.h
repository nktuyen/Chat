#pragma once

#include <WinSock2.h>

class Socket
{
//Properties
public:
protected:
	SOCKET m_sock;
	int m_iAddressFamily;
	int m_iType;
	int m_iProtocol;
private:
//Methods
public:
	Socket(int af, int type, int proto);
	~Socket();
	//Getters
	SOCKET getHandle() { return m_sock; }
	SOCKET getHandle() const { return m_sock; }
	int getAddressFamily() { return m_iAddressFamily; }
	int getAddressFamily() const { return m_iAddressFamily; }
	int getType() { return m_iType; }
	int getType() const { return m_iType; }
	int getProtocol() { return m_iProtocol; }
	int getProtocol() const { return m_iProtocol; }
	//Setters
	//Others
	BOOL Create();
	void Close();
protected:
private:
};

