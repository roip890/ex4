
#ifndef UDPSERVER_H_
#define UDPSERVER_H_
#include "Server.h"
using namespace std;

/*******************************************************************************
* class name : UDPServer
*******************************************************************************/
class UDPServer:public Server{
public:

		UDPServer(ConType type);
		State connect();
		State createSocket();
		State bindSocket();
		State sendData(char* sendData);
		State receiveData();

};

#endif /* UDPSERVER_H_ */
