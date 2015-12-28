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
	/*******************************************************************************
	* function name : ClientConnection										       *
	* input : ip address as string and port number as int.					       *
	* output : nothing.														       *
	* explanation : constructor of a ClientConnection.							   *
	*******************************************************************************/
	ClientConnection(char* ipAddress, int portNum);

	/*******************************************************************************
	* function name : ~TcpConnection										       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : destructor of a TcpConnection.								   *
	*******************************************************************************/
	virtual ~ClientConnection();

	/*******************************************************************************
	* function name : connectSocket											       *
	* input : ip address as string and port number as int.					       *
	* output : nothing.														       *
	* explanation : create socket by ip address and port.						   *
	*******************************************************************************/
	virtual void connectSocket(char* ipAddress, int portNum) = 0;

	/*******************************************************************************
	* function name : getSocket												       *
	* input : nothing.														       *
	* output : socket number.												       *
	* explanation : return the socket number.									   *
	*******************************************************************************/
	virtual int getSocket() = 0;

	/*******************************************************************************
	* function name : getBuffer												       *
	* input : nothing.														       *
	* output : buffer.														       *
	* explanation : return the massage in the buffer member.					   *
	*******************************************************************************/
	virtual char* getBuffer() = 0;

	/*******************************************************************************
	* function name : getSocketAddress										       *
	* input : nothing.														       *
	* output : socket address as struct.									       *
	* explanation : return the socket address as struct.						   *
	*******************************************************************************/
	virtual struct sockaddr_in getSocketAddress() = 0;

	/*******************************************************************************
	* function name : closeSocket											       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : close the socket.											   *
	*******************************************************************************/
	virtual void closeSocket() = 0;

	/*******************************************************************************
	* function name : sendToSocket											       *
	* input : data as string.												       *
	* output : nothing.														       *
	* explanation : send the data to the socket of the constructor.				   *
	*******************************************************************************/
	virtual void sendToSocket(char* data) = 0;

	/*******************************************************************************
	* function name : receiveFromSocket										       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : receive the message to the buffer member from the socket.	   *
	*******************************************************************************/
	virtual void receiveFromSocket() = 0;
};

#endif /* SRC_CLIENTCONNECTION_H_ */
