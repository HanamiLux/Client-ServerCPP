#pragma once

#include <WinSock2.h>
class CClient
{
public:
	CClient();
	~CClient();
	void SendMsg(const char sendBuf[]);
	void RecMsg();
private:
	SOCKET m_sockClient;
	sockaddr_in m_TargetServer;
};

