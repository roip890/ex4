

#include "UDPServer.h"
using namespace std;

UDPServer::UDPServer(ConType type):
		Server(type){
		this->type = type;
		this->ip = 0;
		this->port = 5555;

}


State UDPServer::connect(){
	return SUCCESS;
}

State UDPServer::createSocket(){
	this->socket = socket(AF_INET, SOCK_DGRAM,0);
	if(this->socket < 0){
		perror("error creating socket");
		return FAILURE;
	}

	return SUCCESS;
}

State UDPServer::bindSocket(){
	memset(&this->sin, 0, sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = INADDR_ANY;
	this->sin.sin_port = htons(this->port);

	if(bind(this->socket, (struct sockaddr*)&this->sin,sizeof(this->sin))<0){
		perror("error binding the socket");
		return FAILURE;
	}

	return SUCCESS;


}


State UDPServer::sendData(char* data){
	memset(&this->sin,0,sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = inet_addr(this->ip);
	this->sin.sin_port = htons(this->port);

	int data_len = sizeof(data);

	int sent_bytes = sendto(this->socket, data,data_len,0,(struct sockaddr*)&this->sin,sizeof(this->sin));
	if(sent_bytes<0){
		perror("error writing to socket");
		return FAILURE;
	}

	return SUCCESS;
}


State UDPServer::receiveData(){
	struct sockaddr_in from;
	unsigned int from_len = sizeof(struct sockaddr_in);

	char buffer[4096];

	int bytes = recvfrom(this->socket, buffer,sizeof(buffer),0,(struct sockaddr*)&from,&from_len);

	if(bytes<0){
		perror("error reading from socket");
		return FAILURE;
	}

	return SUCCESS;

}