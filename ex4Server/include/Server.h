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
protected:
	int port;
	struct sockaddr_in sin;
	int sock;
	char* dataReceived;
	char* ip;
public:
	Server();
	Server(int port);
	virtual ~Server();
	virtual void connect()=0;
	void close(int socket);
	int getPort();
	char*  getIP();
	void setIP(char* ip);
	void setPort(int port);
	int getSocket();
	void setSocket(char* ip, int port);
	virtual void sendData(string str)=0;
	virtual void dataReceiver()= 0;
	virtual void bindSocket()=0;
	virtual void createSocket()=0;
	string getDataReceived();
	void setSocket(int sock);
};




#endif /* SERVER_H_ */
