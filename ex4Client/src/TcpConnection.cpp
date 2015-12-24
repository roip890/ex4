/*
 * TcpConnection.cpp
 *
 *  Created on: Dec 22, 2015
 *      Author: roi
 */

#include "TcpConnection.h"
using namespace std;

TcpConnection::TcpConnection(char* ipAddress, int portNum) : ClientConnection(ipAddress, portNum) {
    this->connectSocket(ipAddress, portNum);
}

TcpConnection::~TcpConnection() {
	// TODO Auto-generated destructor stub
}


void TcpConnection::sendToSocket(char* data_addr) {
    int data_len = strlen(data_addr);
    int sent_bytes = send(sock, data_addr, data_len, 0);
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }
}

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
        cout << "The server sent: " << buffer << endl;
    }

}

void TcpConnection::connectSocket(char* ipAddress, int portNum) {
    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    memset(&this->getSocketAddress(), 0, sizeof(this->getSocketAddress()));
    this->getSocketAddress().sin_family = AF_INET;
    this->getSocketAddress().sin_addr.s_addr = inet_addr(ipAddress);
    this->getSocketAddress().sin_port = htons(portNum);

    if (connect(this->getSocket(), (struct sockaddr *)(&(this->getSocketAddress())), sizeof(this->getSocketAddress())) < 0) {
        perror("error connecting to server");
    }
}

int TcpConnection::getSocket() {
	return this->sock;
}

char*& TcpConnection::getBuffer() {
	return this->buffer;
}

struct sockaddr_in& TcpConnection::getSocketAddress() {
	return this->sin;
}

void TcpConnection::closeSocket() {
	close(this->getSocket());
}


