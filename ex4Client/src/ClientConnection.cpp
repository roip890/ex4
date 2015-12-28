/*
 * ClientConnection.cpp
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#include "ClientConnection.h"

/*******************************************************************************
* function name : ClientConnection										       *
* input : ip address as string and port number as int.					       *
* output : nothing.														       *
* explanation : constructor of a ClientConnection.							   *
*******************************************************************************/
ClientConnection::ClientConnection(char* ipAddress, int portNum){ }

/*******************************************************************************
* function name : ~ClientConnection										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : destructor of a ClientConnection.							   *
*******************************************************************************/
ClientConnection::~ClientConnection() { }

/*******************************************************************************
* function name : sendToSocket											       *
* input : data as string.												       *
* output : nothing.														       *
* explanation : send the data to the socket of the constructor.				   *
*******************************************************************************/
void ClientConnection::sendToSocket(char* data) { }

/*******************************************************************************
* function name : receiveFromSocket										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : receive the message to the buffer member from the socket.	   *
*******************************************************************************/
void ClientConnection::receiveFromSocket(){ }

/*******************************************************************************
* function name : connectSocket											       *
* input : ip address as string and port number as int.					       *
* output : nothing.														       *
* explanation : create socket by ip address and port.						   *
*******************************************************************************/
void ClientConnection::connectSocket(char* ipAddress, int portNum) { }

/*******************************************************************************
* function name : closeSocket											       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : close the socket.											   *
*******************************************************************************/
void ClientConnection::closeSocket() { }
