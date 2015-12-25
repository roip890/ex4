#include "TCPServer.h"


TCPServer::TCPServer(int port):
	Server(port){
	this->client_sock =0;
	this->createSocket();
	this->bindSocket();
	this->connect();
	this->connEstablish();
}

TCPServer::~TCPServer(){

}


void TCPServer::connect(){


	int back_log = 1; //need to change
	if (listen(this->getSocket(), back_log) < 0) {
		perror("error listening to a socket");
	}
}


void TCPServer::createSocket(){

	this->sock = socket(AF_INET,SOCK_STREAM,0);

	if(this->getSocket() < 0){
        perror("error creating socket");
	}


}
void TCPServer::setSocket(char* ip,int sock){
	this->sock = sock;
	this->ip = NULL;
}
void TCPServer::bindSocket(){

	memset(&this->sin, 0, sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = INADDR_ANY;
	this->sin.sin_port = htons(this->port);

	if (bind(this->sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
		perror("error binding socket");
	}


}

void TCPServer::connEstablish(){

	unsigned int addr_len = sizeof(this->client_sin);

	this->client_sock = accept(this->getSocket(), (struct sockaddr *)&(this->client_sin),  &addr_len);

	if (client_sock < 0) {
		perror("error accepting client");
	}


}



void TCPServer::sendData(string data){

	int data_len = data.length();
	int sent_bytes = send(this->client_sock, data.c_str(), data_len, 0);
	if (sent_bytes < 0) {
		perror("error sending to client");
	}

}


void TCPServer::dataReceiver(){

	char buffer[4096];
	int expected_data_len = sizeof(buffer);
	int read_bytes = recv(this->client_sock, buffer, expected_data_len, 0);
	if (read_bytes == 0) {
		cout<<"connection is close\n";
	}
	else if (read_bytes < 0) {
		perror("error reading from client");
	}
	this->dataReceived=buffer;


}
