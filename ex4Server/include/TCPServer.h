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

		TCPServer( int port);
		State connect();
		State initializeServer();
		State connEstablish();

};



#endif /* TCPSERVER_H_ */
