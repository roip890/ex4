/*
 * TcpConnection.h
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#ifndef SRC_TCPCONNECTION_H_
#define SRC_TCPCONNECTION_H_
#include "ClientConnection.h"
class TcpConnection : public ClientConnection{
private:
	int sock;
    struct sockaddr_in sin;
    char* buffer;
public:
    TcpConnection(char* ipAddress, int portNum);
	virtual ~TcpConnection();
	void connectSocket(char* ipAddress, int portNum);
	int getSocket();
	char*& getBuffer();
	struct sockaddr_in& getSocketAddress();
	void closeSocket();
	void sendToSocket(char* data);
	void receiveFromSocket();
};

#endif /* SRC_TCPCONNECTION_H_ */

