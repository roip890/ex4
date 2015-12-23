
#include "Server.h"
using namespace std;


Server::Server(ConType type){
	this->type = type;
	this->port =0;
	this->ip = 0;
}

Server::Server(ConType type, int ip, int port){
	this->type = type;
	this->ip = ip;
	this->port = port;


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


