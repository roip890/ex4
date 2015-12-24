//main.cpp

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include "MoviesSystem.h"
#include "gtest.h"
using namespace std;

enum ConType{TCP, UDP};
int main(int argc, char* argv[]) {
	char* ipAddress = "127.0.0.1";
	int portNum = 5555;
	ClientConnection* con;
	int type;
	cin >> type;
	if (type == TCP) {
		con = new TcpConnection(ipAddress, portNum);
	} else {
		con = new UdpConnection(ipAddress, portNum);
	}

	int key;
	string command;
	do{
		getline(cin, command);
		con->sendToSocket((char*)(command.c_str()));
		con->receiveFromSocket();
		cout << con->getBuffer();
	}while (re);

	}
    return 0;
}
