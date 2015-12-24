/*
 * UdpConnection.h
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#ifndef SRC_UDPCONNECTION_H_
#define SRC_UDPCONNECTION_H_
#include "ClientConnection.h"

class UdpConnection : public ClientConnection{
private:
	int sock;
    struct sockaddr_in sin;
    char* buffer;
public:
    UdpConnection(char* ipAddress, int portNum);
	virtual ~UdpConnection();
	void connectSocket(char* ipAddress, int portNum);
	int getSocket();
	char*& getBuffer();
	struct sockaddr_in& getSocketAddress();
	void closeSocket();
	void sendToSocket(char* data);
	void receiveFromSocket();
};

#endif /* SRC_UDPCONNECTION_H_ */
