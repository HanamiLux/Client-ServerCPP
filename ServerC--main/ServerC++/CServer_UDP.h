#pragma once

#include <winsock2.h>
#include <string>

class CServer_UDP
{
public:
	CServer_UDP();
	~CServer_UDP();
	void SendMsg(const char sendBuf[]);
	void RecMsg();
	std::string GetAnswer();
private:
	SOCKET m_sSeerver;
	struct sockaddr_in m_SocAddrClient;
	bool m_terminal;
	std::string answer;
};

