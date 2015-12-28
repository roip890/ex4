/*
 * UdpConnection.cpp
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#include "UdpConnection.h"
using namespace std;

/*******************************************************************************
* function name : UdpConnection											       *
* input : ip address as string and port number as int.					       *
* output : nothing.														       *
* explanation : constructor of a UdpConnection.								   *
*******************************************************************************/
UdpConnection::UdpConnection(char* ipAddress, int portNum) : ClientConnection(ipAddress, portNum) {
    this->connectSocket(ipAddress, portNum);
}

/*******************************************************************************
* function name : ~UdpConnection										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : destructor of a UdpConnection.								   *
*******************************************************************************/
UdpConnection::~UdpConnection() {
	// TODO Auto-generated destructor stub
}

/*******************************************************************************
* function name : sendToSocket											       *
* input : data as string.												       *
* output : nothing.														       *
* explanation : send the data to the socket of the constructor.				   *
*******************************************************************************/
void UdpConnection::sendToSocket(char* data) {
    int sent_bytes = sendto(this->getSocket(), data, strlen(data), 0, (struct sockaddr *)(&(this->sin)), sizeof(this->sin));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
}

/*******************************************************************************
* function name : receiveFromSocket										       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : receive the message to the buffer member from the socket.	   *
*******************************************************************************/
void UdpConnection::receiveFromSocket(){
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    memset(&(this->buffer), 0, sizeof(this->buffer));
    int bytes = recvfrom(this->getSocket(), this->buffer, sizeof(this->buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }

    cout <<buffer;
}

/*******************************************************************************
* function name : connectSocket											       *
* input : ip address as string and port number as int.					       *
* output : nothing.														       *
* explanation : create socket by ip address and port.						   *
*******************************************************************************/
void UdpConnection::connectSocket(char* ipAddress, int portNum) {
    this->sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->getSocket() < 0) {
        perror("error creating socket");
    }
    memset(&this->sin, 0, sizeof(this->sin));
    this->sin.sin_family = AF_INET;
    this->sin.sin_addr.s_addr = inet_addr(ipAddress);
    this->sin.sin_port = htons(portNum);
}

/*******************************************************************************
* function name : getSocket												       *
* input : nothing.														       *
* output : socket number.												       *
* explanation : return the socket number.									   *
*******************************************************************************/
int UdpConnection::getSocket() {
	return this->sock;
}

/*******************************************************************************
* function name : getBuffer												       *
* input : nothing.														       *
* output : buffer.														       *
* explanation : return the massage in the buffer member.					   *
*******************************************************************************/
char* UdpConnection::getBuffer() {
	return this->buffer;
}

/*******************************************************************************
* function name : getSocketAddress										       *
* input : nothing.														       *
* output : socket address as struct.									       *
* explanation : return the socket address as struct.						   *
*******************************************************************************/
struct sockaddr_in UdpConnection::getSocketAddress() {
	return this->sin;
}

/*******************************************************************************
* function name : closeSocket											       *
* input : nothing.														       *
* output : nothing.														       *
* explanation : close the socket.											   *
*******************************************************************************/
void UdpConnection::closeSocket() {
	close(this->getSocket());
}
