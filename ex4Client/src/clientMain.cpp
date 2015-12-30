/**
 * Tomer Rahamim 203717475
 * Roi Peretz 203258041
 */
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
	if(argc-1!= 3){
		cout<<"missing arguments - exit"<<endl;
		return 0;
	}
	int port = atoi(argv[3]);
	if(port < 1024 || port > 65563){
		cout<< "invalid port number"<<endl;
		return 0;
	}
	//create the connection.
	char* ipAddress = argv[2];
	ClientConnection* con;
	int type = atoi(argv[1]);
	if (type == TCP) {
		con = new TcpConnection(ipAddress, port);
	} else {
		con = new UdpConnection(ipAddress, port);
	}
	//enter the next command and get the answer.
	string command;
	do{
		getline(cin, command);
		con->sendToSocket((char*)(command.c_str()));
		con->receiveFromSocket();
		if(con->getBuffer() == "-1"){
			break;
		}
	}while (true);


    return 0;
}
