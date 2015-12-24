/*
 * UdpConnection.cpp
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#include "UdpConnection.h"
using namespace std;

UdpConnection::UdpConnection(char* ipAddress, int portNum) : ClientConnection(ipAddress, portNum) {
    this->connectSocket(ipAddress, portNum);
}

UdpConnection::~UdpConnection() {
	// TODO Auto-generated destructor stub
}


void UdpConnection::sendToSocket(char* data) {
    int sent_bytes = sendto(this->getSocket(), data, strlen(data), 0, (struct sockaddr *)(&(this->getSocketAddress())), sizeof(this->getSocketAddress()));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
}

void UdpConnection::receiveFromSocket(){
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    memset(&(this->getBuffer()), 0, sizeof(this->getBuffer()));
    int bytes = recvfrom(this->getSocket(), this->getBuffer(), sizeof(this->getBuffer()), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }

    cout << "The server sent: " << buffer << endl;
}

void UdpConnection::connectSocket(char* ipAddress, int portNum) {
    this->sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->getSocket() < 0) {
        perror("error creating socket");
    }
    memset(&this->getSocketAddress(), 0, sizeof(this->getSocketAddress()));
    this->getSocketAddress().sin_family = AF_INET;
    this->getSocketAddress().sin_addr.s_addr = inet_addr(ipAddress);
    this->getSocketAddress().sin_port = htons(portNum);
}

int UdpConnection::getSocket() {
	return this->sock;
}

char*& UdpConnection::getBuffer() {
	return this->buffer;
}

struct sockaddr_in& UdpConnection::getSocketAddress() {
	return this->sin;
}

void UdpConnection::closeSocket() {
	close(this->getSocket());
}
