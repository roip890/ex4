
#include "Server.h"
using namespace std;


Server::Server(){
	this->port =0;
	this->dataReceived =NULL;
	this->sock = 0;
	this->ip = NULL;
}
Server::~Server(){

}

Server::Server( int port){
	this->port = port;
	this->dataReceived =NULL;
	this->ip = NULL;
	this->sock = 0;
}

char* Server::getIP(){
	return this->ip;
}
int Server::getPort(){
	return this->port;
}
void Server::setIP(char*  ip){
	this->ip=ip;
}
void Server::setPort(int port){
	this->port=port;
}

void Server::close(int socket){
	close(socket);
}
string Server::getDataReceived(){
	return string(this->dataReceived);
}
int Server::getSocket(){
	return this->sock;
}
void Server::sendData(string str){}
void Server::dataReceiver(){}
void Server::bindSocket(){}
//void Server::createSocket(){}
