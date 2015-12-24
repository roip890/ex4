

#include "UDPServer.h"
using namespace std;

UDPServer::UDPServer(int port):
		Server(port){
		this->port = port;
		this->createSocket();
		this->bindSocket();

}
UDPServer::~UDPServer(){

}

void UDPServer::connect(){
}

void UDPServer::createSocket(){
	this->sock = socket(AF_INET, SOCK_DGRAM,0);
	if(this->sock < 0){
		perror("error creating socket");
	}

}

void UDPServer::bindSocket(){
	memset(&this->sin, 0, sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = INADDR_ANY;
	this->sin.sin_port = htons(this->port);

	if(bind(this->sock, (struct sockaddr*)&this->sin,sizeof(this->sin))<0){
		perror("error binding the socket");
	}

}


void UDPServer::sendData(string data){
	memset(&this->sin,0,sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = inet_addr(this->ip);
	this->sin.sin_port = htons(this->port);

	int data_len = sizeof(data);

	int sent_bytes = sendto(this->sock, data.c_str(),data_len,0,(struct sockaddr*)&this->sin,sizeof(this->sin));
	if(sent_bytes<0){
		perror("error writing to socket");
	}

}


void UDPServer::dataReceiver(){
	struct sockaddr_in from;
	unsigned int from_len = sizeof(struct sockaddr_in);

	char buffer[4096];

	int bytes = recvfrom(this->sock, buffer,sizeof(buffer),0,(struct sockaddr*)&from,&from_len);

	if(bytes<0){
		perror("error reading from socket");
	}

}
