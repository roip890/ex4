#include "UDPServer.h"
using namespace std;

/*******************************************************************************
 * function name : UDPServer											       *
 * input : nothing.														       *
 * output : ip as string.												       *
 * explanation : constructor of a UDPServer.								   *
 *******************************************************************************/
UDPServer::UDPServer(int port) :
		Server(port) {
	this->port = port;
	this->createSocket();
	this->bindSocket();

}

/*******************************************************************************
 * function name : ~UDPServer											       *
 * input : nothing.														       *
 * output : nothing.													       *
 * explanation : destructor of a UDPServer.									   *
 *******************************************************************************/
UDPServer::~UDPServer() {

}

/*******************************************************************************
 * function name : connect												       *
 * input : connect to a certain socket.									       *
 * output : nothing.													       *
 * explanation : sending the data to the socket.							   *
 *******************************************************************************/
void UDPServer::connect() {
}

/*******************************************************************************
 * function name : createSocket											       *
 * input : nothing.														       *
 * output : nothing.													       *
 * explanation : creating a socket in this connection.						   *
 *******************************************************************************/
void UDPServer::createSocket() {
	this->sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (this->sock < 0) {
		perror("error creating socket");
	}

}

/*******************************************************************************
 * function name : bindSocket											       *
 * input : nothing.														       *
 * output : nothing.													       *
 * explanation : make bind to a client.										   *
 *******************************************************************************/
void UDPServer::bindSocket() {
	memset(&this->sin, 0, sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = INADDR_ANY;
	this->sin.sin_port = htons(this->port);

	if (bind(this->sock, (struct sockaddr*) &this->sin, sizeof(this->sin))
			< 0) {
		perror("error binding the socket");
	}

}

/*******************************************************************************
 * function name : sendData												       *
 * input : data as string.												       *
 * output : nothing.													       *
 * explanation : sending the data to the socket.							   *
 *******************************************************************************/
void UDPServer::sendData(string data) {

	char buffer[4096];
	memset(&buffer, 0, sizeof(buffer));

	int data_len = data.size();

	int sent_bytes = sendto(this->sock, data.c_str(), data_len, 0,
			(struct sockaddr *) &this->sin, sizeof(this->sin));
	if (sent_bytes < 0) {
		perror("error writing to socket");
	}

}

/*******************************************************************************
 * function name : dataReceiver											       *
 * input : nothing.														       *
 * output : nothing.													       *
 * explanation : receive the massage to the buffer.							   *
 *******************************************************************************/
void UDPServer::dataReceiver() {
	struct sockaddr_in from;
	unsigned int from_len = sizeof(struct sockaddr_in);

	char buffer[4096];
	memset(&(buffer), 0, sizeof(buffer));
	int bytes = recvfrom(this->sock, buffer, sizeof(buffer), 0,
			(struct sockaddr*) &this->sin, &from_len);

	if (bytes < 0) {
		perror("error reading from socket");
	}
	this->dataReceived = buffer;
}
