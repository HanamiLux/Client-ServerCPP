#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "CClient.h"

#include <iostream>

#include <string>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

CClient::CClient() {
	WORD sockVersion = MAKEWORD(2, 2);

	WSADATA wsaDATA;

	if (WSAStartup(sockVersion, &wsaDATA) != 0) {
		cout << "Initialize WSA failed" << endl;
		return;
	}
	m_sockClient = socket(AF_INET, SOCK_DGRAM, 0);
	m_TargetServer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	m_TargetServer.sin_family = AF_INET;
	m_TargetServer.sin_port = htons(8027);


	if (m_sockClient == -1) {
		cout << "Create socket failed!" << std::endl;
		WSACleanup();
	}
	else {
		SendMsg("message");
	}

}

void CClient::SendMsg(const char sendBuf[]) {
	sendto(m_sockClient, sendBuf, strlen(sendBuf), 0, (sockaddr*)&m_TargetServer, sizeof(m_TargetServer));

}

void CClient::RecMsg() {
	

	//while (1) {
		char recBuf[1025];
		int len = recvfrom(m_sockClient, recBuf, 1024, 0, 0, 0);
		if (len > 0) {
			recBuf[len] = '\0';
			cout << "Server: " << recBuf << endl;
		}
	/*}*/
}

CClient::~CClient()
{
	closesocket(m_sockClient);
	WSACleanup();
}
