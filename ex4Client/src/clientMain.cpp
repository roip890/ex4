//main.cpp

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include "ClientConnection.h"
#include "TcpConnection.h"
#include "UdpConnection.h"
using namespace std;

enum ConType{TCP, UDP};
int main(int argc, char* argv[]) {
	if(argc!= 3){
		cout<<"missing arguments - exit"<<endl;
		return 0;
	}
	int port = atoi(argv[2]);
	if(port < 1024 || port > 65563){
		cout<< "invalid port number"<<endl;
		return 0;
	}

	char* ipAddress = argv[1];
	ClientConnection* con;
	int type;
	cin >> type;
	if (type == TCP) {
		con = new TcpConnection(ipAddress, port);
	} else {
		con = new UdpConnection(ipAddress, port);
	}

	string command;
	do{
		getline(cin, command);
		con->sendToSocket((char*)(command.c_str()));
		con->receiveFromSocket();
		if(con->getBuffer() == "-1"){
			break;
		}
		cout << con->getBuffer();
	}while (true);


    return 0;
}
