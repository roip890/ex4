
#ifndef UDPSERVER_H_
#define UDPSERVER_H_
#include "Server.h"
using namespace std;

/*******************************************************************************
* class name : UDPServer
*******************************************************************************/
class UDPServer:public Server{
public:

		UDPServer(int port);
		State bindSocket();
		State sendData(char* data);
		State dataReceiver();
		State bindServer();
		State createSocket();
		State connect();
		string getDataReceived();
};

#endif /* UDPSERVER_H_ */
