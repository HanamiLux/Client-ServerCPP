// ClientC++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <string>
#include <thread>
#include "CClient.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	CClient client;
	//thread RecProc(&CClient::RecMsg, &client);
	while (true) {
		cout << "Введите число: ";
		string message;
		cin >> message;
		client.SendMsg(message.c_str());
		client.RecMsg();
	}
	//RecProc.join();
	system("pause");
	return 0;
}
