#include "TCPServer.h"


TCPServer::TCPServer(ConType type, int ip, int port):
	Server(type, ip, port){
	this->type = type;
	this->ip = ip;
	this->port = port;
	this->client_sock =0;
	this->initializeServer();
	this->bindServer();
	this->connEstablish();
}




State TCPServer::connect(){

	this->initializeServer();
	this->bindServer();
	int back_log = 5; //need to change
	if (listen(this->socket, back_log) < 0) {
		perror("error listening to a socket");
		return FAILURE;
	}

	return this->close(this->socket);
}


State TCPServer::initializeServer(){

	this->socket = socket(AF_INET,SOCK_STREAM,0);

	if(this->socket < 0){
        perror("error creating socket");
        return FAILURE;
	}

	return SUCCESS;

}

State TCPServer::bindServer(){

	memset(&this->sin, 0, sizeof(this->sin));
	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = INADDR_ANY;
	this->sin.sin_port = htons(this->port);

	if (bind(this->socket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
		perror("error binding socket");
		return FAILURE;
	}

	return SUCCESS;

}

State TCPServer::connEstablish(){

	unsigned int addr_len = sizeof(this->client_sin);
	this->client_sock = accept(this->socket,  (struct sockaddr *) &this->client_sin,  &addr_len);

	if (client_sock < 0) {
		perror("error accepting client");
		return FAILURE;
	}

	return SUCCESS;

}



State TCPServer::sendData(char* data){

	int data_len = sizeof(data);
	int sent_bytes = send(this->client_sock, data, data_len, 0);
	if (sent_bytes < 0) {
		perror("error sending to client");
		return FAILURE;
	}
	return SUCCESS;

}


State TCPServer::dataReceiver(){

	char buffer[4096];
	int expected_data_len = sizeof(buffer);
	int read_bytes = recv(this->client_sock, buffer, expected_data_len, 0);
	if (read_bytes == 0) {
		cout<<"connection is close\n";
		return FAILURE;
	}
	else if (read_bytes < 0) {
		perror("error reading from client");
		return FAILURE;
	}
	else {
		cout << buffer;
	}

	return SUCCESS;

}
