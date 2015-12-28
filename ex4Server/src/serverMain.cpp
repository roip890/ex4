//main.cpp

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include "MoviesSystem.h"
#include "Server.h"
#include "UDPServer.h"
#include "TCPServer.h"

using namespace std;
int main(int argc, char* argv[]) {
	Server* server;

	if(argc-1!= 2){
		cout<<"Missing arguments - exit"<<endl;
		return 0;
	}

	int port = atoi(argv[2]);
	int type = atoi(argv[1]);
	if(port< 1024 || port>65536){
		cout<<"invalid port number - exit"<<endl;
		return 0;
	}

	// creating a connection.
	switch(type){
	case 0:
		server = new TCPServer(port);
		break;
	case 1:
		server = new UDPServer(port);
		break;
	default:
		cout<<"wrong connection type - exit"<<endl;
		return 0;
	}


	//starting the movies system.
	MoviesSystem* ms = new MoviesSystem(server);
	(*ms).start();
	return 0;
}
