/*
 * TcpConnection.cpp
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#include "TcpConnection.h"
using namespace std;

/*******************************************************************************
* function name : TcpConnection											       *
* input : ip address as string and port number as int.					       *
* output : nothing.														       *
* explanation : constructor of a TcpConnection.								   *
*******************************************************************************/
TcpConnection::TcpConnection(char* ipAddress, int portNum) : ClientConnection(ipAddress, portNum) {
    this->connectSocket(ipAddress, portNum);
}

/*******************************************************************************
* function name : ~TcpConnection										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : destructor of a TcpConnection.								   *
*******************************************************************************/
TcpConnection::~TcpConnection() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : sendToSocket											       *
* input : data as string.												       *
* output : nothing.														       *
* explanation : send the data to the socket of the constructor.				   *
*******************************************************************************/
void TcpConnection::sendToSocket(char* data_addr) {
    int data_len = strlen(data_addr);
    int sent_bytes = send(sock, data_addr, data_len, 0);
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
}

/*******************************************************************************
 * function name : receiveFromSocket									       *
 * input : nothing.														       *
 * output : nothing.													       *
 * explanation : receive the message to the buffer member from the socket.	   *
 *******************************************************************************/
void TcpConnection::receiveFromSocket(){
    int expected_data_len = sizeof(this->getBuffer());
    int read_bytes = recv(this->getSocket(), this->getBuffer(), expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is closed");
    }
    else if (read_bytes < 0) {
        perror("error reading from socket");
    }
    else {
        cout << buffer;
    }

}

/*******************************************************************************
* function name : connectSocket											       *
* input : ip address as string and port number as int.					       *
* output : nothing.														       *
* explanation : create socket by ip address and port.						   *
*******************************************************************************/
void TcpConnection::connectSocket(char* ipAddress, int portNum) {
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    memset(&this->sin, 0, sizeof(this->getSocketAddress()));
    this->sin.sin_family = AF_INET;
    this->sin.sin_addr.s_addr = inet_addr(ipAddress);
    this->sin.sin_port = htons(portNum);

    if (connect(this->getSocket(), (struct sockaddr *)&this->sin, sizeof(this->sin)) < 0) {
        perror("error connecting to server");
    }
}

/*******************************************************************************
* function name : getSocket												       *
* input : nothing.														       *
* output : socket number.												       *
* explanation : return the socket number.									   *
*******************************************************************************/
int TcpConnection::getSocket() {
	return this->sock;
}

/*******************************************************************************
* function name : getBuffer												       *
* input : nothing.														       *
* output : buffer.														       *
* explanation : return the massage in the buffer member.					   *
*******************************************************************************/
char* TcpConnection::getBuffer() {
	return this->buffer;
}

/*******************************************************************************
* function name : getSocketAddress										       *
* input : nothing.														       *
* output : socket address as struct.									       *
* explanation : return the socket address as struct.						   *
*******************************************************************************/
struct sockaddr_in TcpConnection::getSocketAddress() {
	return this->sin;
}

/*******************************************************************************
* function name : closeSocket											       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : close the socket.											   *
*******************************************************************************/
void TcpConnection::closeSocket() {
	close(this->getSocket());
}
