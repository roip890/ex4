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

public:
	/*******************************************************************************
	* function name : TcpConnection											       *
	* input : ip address as string and port number as int.					       *
	* output : nothing.														       *
	* explanation : constructor of a TcpConnection.								   *
	*******************************************************************************/
    TcpConnection(char* ipAddress, int portNum);

    /*******************************************************************************
    * function name : ~TcpConnection										       *
    * input : nothing.														       *
    * output : nothing.														       *
    * explanation : destructor of a TcpConnection.								   *
    *******************************************************************************/
	virtual ~TcpConnection();

	/*******************************************************************************
	* function name : connectSocket											       *
	* input : ip address as string and port number as int.					       *
	* output : nothing.														       *
	* explanation : create socket by ip address and port.						   *
	*******************************************************************************/
	void connectSocket(char* ipAddress, int portNum);

	/*******************************************************************************
	* function name : getSocket												       *
	* input : nothing.														       *
	* output : socket number.												       *
	* explanation : return the socket number.									   *
	*******************************************************************************/
	int getSocket();

	/*******************************************************************************
	* function name : getBuffer												       *
	* input : nothing.														       *
	* output : buffer.														       *
	* explanation : return the massage in the buffer member.					   *
	*******************************************************************************/
	char* getBuffer();

	/*******************************************************************************
	* function name : getSocketAddress										       *
	* input : nothing.														       *
	* output : socket address as struct.									       *
	* explanation : return the socket address as struct.						   *
	*******************************************************************************/
	struct sockaddr_in getSocketAddress();

	/*******************************************************************************
	* function name : closeSocket											       *
	* input : nothing.														       *
	* output : nothing.														       *
	* explanation : close the socket.											   *
	*******************************************************************************/
	void closeSocket();

	/*******************************************************************************
	* function name : sendToSocket											       *
	* input : data as string.												       *
	* output : nothing.														       *
	* explanation : send the data to the socket of the constructor.				   *
	*******************************************************************************/
	void sendToSocket(char* data);

	/*******************************************************************************
	 * function name : receiveFromSocket									       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : receive the message to the buffer member from the socket.	   *
	 *******************************************************************************/
	void receiveFromSocket();
};

#endif /* SRC_TCPCONNECTION_H_ */

