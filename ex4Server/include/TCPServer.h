/*
 * TCPServer.h
 *
 *  Created on: Dec 23, 2015
 *      Author: tomericko
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_
#include "Server.h"

/*******************************************************************************
* class name : TCPServer
*******************************************************************************/
class TCPServer:public Server{
private:
	struct sockaddr_in client_sin;
	int client_sock;
public:
		~TCPServer();
		TCPServer( int port);
		void connect();
		void connEstablish();
		string getDataReceived();
		void sendData(string data);
		void dataReceiver();
		void bindSocket();
		void setSocket(char* ip, int port);
		void createSocket();

};



#endif /* TCPSERVER_H_ */
