/*
 * ClientConnection.cpp
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#include "ClientConnection.h"

ClientConnection::ClientConnection(char* ipAddress, int portNum){
	//this->connectSocket(ipAddress, portNum);
}

ClientConnection::~ClientConnection() { }

void ClientConnection::sendToSocket(char* data) { }

void ClientConnection::receiveFromSocket(){ }

void ClientConnection::connectSocket(char* ipAddress, int portNum) { }




void ClientConnection::closeSocket() { }
