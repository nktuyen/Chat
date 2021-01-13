#include "pch.h"
#include "SocketTCP.h"

SocketTCP::SocketTCP(int af)
	: Socket(af, SOCK_STREAM, IPPROTO_TCP)
{

}


SocketTCP::~SocketTCP()
{

}