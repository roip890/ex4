//main.cpp

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include "MoviesSystem.h"
#include "gtest.h"
#include "Server.h"

using namespace std;
GTEST_API_ int main(int argc, char* argv[]) {
	Server* server;

	if(argc!= 2){
		cout<<"Missing arguments - exit"<<endl;
		return 0;
	}

	int port = atoi(argv[1]);
	int type = atoi(argv[0]);
	if(port< 1024 || port>65536){
		cout<<"invalid port number - exit"<<endl;
		return 0;
	}


	switch(argv[0]){
	case 0:
		server = new UDPServer(argv[0]);
		break;
	case 1:
		server = new TCPServer(argv[1]);
		break;
	default:
		cout<<"wrong connection type - exit"<<endl;
		return 0;
	}



	MoviesSystem* ms = new MoviesSystem();
	(*ms).start();

}
