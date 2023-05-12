#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "CServer_UDP.h"

#pragma comment(lib, "ws2_32.lib")
#include <iostream>
#include <string>

using namespace std;

CServer_UDP::CServer_UDP() : m_terminal(false) {
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;

	if (WSAStartup(sockVersion, &wsaData) != 0) {
		cout << "Initialize WSA failed" << endl;
	}

	m_sSeerver = socket(AF_INET, SOCK_DGRAM, 0);

	struct sockaddr_in m_SocAddrserver;

	m_SocAddrserver.sin_addr.S_un.S_addr = 0;
	m_SocAddrserver.sin_family = AF_INET;
	m_SocAddrserver.sin_port = htons(8027);

	int ret = bind(m_sSeerver, (sockaddr*)&m_SocAddrserver, sizeof(m_SocAddrserver));
	if (ret == -1) {
		cout << "bind failed!" << endl;
		WSACleanup();
	}
	else {
		int len_Client = sizeof(sockaddr);

		char recBuf[1025];

		int len = recvfrom(m_sSeerver, recBuf, 1024, 0, (sockaddr*)&m_SocAddrClient, &len_Client);
		if (len > 0) {
			recBuf[len] = '\0';
			
			cout << "Client say: " << recBuf << endl;
		}
		else {
			cout << "Client say: " << recBuf << endl;

		}
	}
}


void CServer_UDP::SendMsg(const char sendBuf[]) {
	int ret = sendto(m_sSeerver, sendBuf, strlen(sendBuf), 0, (sockaddr*)&m_SocAddrClient, sizeof(m_SocAddrClient));

	if (ret == -1) {
		cout << "send failed" << endl;
		cout << GetLastError << endl;
	}
}
std::string CServer_UDP::GetAnswer() {
	return answer;
}

void CServer_UDP::RecMsg() {
	char recBuf[1025];
	/*while (!m_terminal) {*/
		int len = recvfrom(m_sSeerver, recBuf, 1024, 0, 0, 0);
		if (len > 0) {
			recBuf[len] = '\0';
			string str(recBuf);
			answer = str;
			cout << "Client trying: " << str << endl;
		}
	/*}*/
}

CServer_UDP::~CServer_UDP() {
	closesocket(m_sSeerver);
	WSACleanup();
}
