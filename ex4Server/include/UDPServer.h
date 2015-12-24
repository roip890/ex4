
#ifndef UDPSERVER_H_
#define UDPSERVER_H_
#include "Server.h"
using namespace std;

/*******************************************************************************
* class name : UDPServer
*******************************************************************************/
class UDPServer:public Server{
public:
		~UDPServer();
		UDPServer(int port);
		void bindSocket();
		void sendData(string data);
		void createSocket();
		void connect();
		string getDataReceived();
		void dataReceiver();
};

#endif /* UDPSERVER_H_ */
