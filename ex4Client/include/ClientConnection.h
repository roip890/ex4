/*
 * ClientConnection.h
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#ifndef SRC_CLIENTCONNECTION_H_
#define SRC_CLIENTCONNECTION_H_
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

class ClientConnection {
protected:
	int sock;
	struct sockaddr_in sin;
	char buffer[4096];
public:
	ClientConnection(char* ipAddress, int portNum);
	virtual ~ClientConnection();
	virtual void connectSocket(char* ipAddress, int portNum) = 0;
	virtual int getSocket() = 0;
	virtual char* getBuffer() = 0;
	virtual struct sockaddr_in getSocketAddress() = 0;
	virtual void closeSocket() = 0;
	virtual void sendToSocket(char* data) = 0;
	virtual void receiveFromSocket() = 0;
};

#endif /* SRC_CLIENTCONNECTION_H_ */
