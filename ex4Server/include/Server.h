/*
 * Server.h
 *
 *  Created on: Dec 22, 2015
 *      Author: tomericko
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

enum ConType{TCP, UDP};
enum State{FAILURE, SUCCESS};
using namespace std;

/*******************************************************************************
* class name : Server
*******************************************************************************/
class Server{
private:
	int port;
	struct sockaddr_in sin;
	int socket;
	char* dataReceived;
	char* ip;
public:
	Server();
	Server(int port);

	State connect();
	State close(int socket);
	int getPort();
	int getIP();
	void setIP(int ip);
	void setPort(int port);
	struct sockaddr_in getSocket();
	void setSocket(char* ip, int port);
	State sendData(char* data);
	State dataReceiver();
	State bindServer();
	State createSocket();
	string getDataReceived();
	//try
};




#endif /* SERVER_H_ */
