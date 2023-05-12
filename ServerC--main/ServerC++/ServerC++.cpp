#include "CServer_UDP.h"
#include <string>
#include <thread>
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	CServer_UDP serverUdp;

	//thread recProc(&CServer_UDP::RecMsg, &serverUdp);
	int firstNum = 44;
	int num = 0;
	srand((unsigned)time(0));
	while (1) {
		serverUdp.RecMsg();
		string content;

		try {
		num = stoi(serverUdp.GetAnswer());
		}
		catch (exception) { num = 0; }
		if (num == firstNum) {
			content = "Client win! He said: " + serverUdp.GetAnswer();
			cout << content << endl;
			serverUdp.SendMsg(content.c_str());
			firstNum = rand();
			cout << "New number is " << firstNum << endl;

		}
		else if (num > firstNum) {
			content = "Nah.., try number less then " + serverUdp.GetAnswer();
			cout << content << endl;
			serverUdp.SendMsg(content.c_str());
		}
		else if (num < firstNum) {
			content = "Nah.., try number more then " + serverUdp.GetAnswer();
			cout << content << endl;
			serverUdp.SendMsg(content.c_str());
		}
	}
	//recProc.join();
	system("pause");
}
