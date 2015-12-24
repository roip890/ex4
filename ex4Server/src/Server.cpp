
#include "Server.h"
using namespace std;


Server::Server(){
	this->port =0;
	this->dataReceived =NULL;
	this->socket = NULL;
	this->ip = NULL;
}

Server::Server( int port){
	this->port = port;
	this->dataReceived =NULL;
	this->socket = NULL;
	this->ip = NULL;

}

int Server::getIP(){
	return this->ip;
}
int Server::getPort(){
	return this->port;
}
void Server::setIP(int ip){
	this->ip=ip;
}
void Server::setPort(int port){
	this->port=port;
}

State Server::close(int socket){
	close(socket);
	return SUCCESS;
}
string Server::getDataReceived(){
	return string(this->dataReceived);
}

