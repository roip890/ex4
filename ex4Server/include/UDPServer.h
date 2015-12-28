#ifndef UDPSERVER_H_
#define UDPSERVER_H_
#include "Server.h"
using namespace std;

/*******************************************************************************
 * class name : UDPServer
 *******************************************************************************/
class UDPServer: public Server {
public:
	/*******************************************************************************
	 * function name : ~UDPServer											       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : destructor of a UDPServer.									   *
	 *******************************************************************************/
	~UDPServer();

	/*******************************************************************************
	 * function name : UDPServer											       *
	 * input : nothing.														       *
	 * output : ip as string.												       *
	 * explanation : constructor of a UDPServer.								   *
	 *******************************************************************************/
	UDPServer(int port);

	/*******************************************************************************
	 * function name : bindSocket											       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : make bind to a client.										   *
	 *******************************************************************************/
	void bindSocket();

	/*******************************************************************************
	 * function name : sendData												       *
	 * input : data as string.												       *
	 * output : nothing.													       *
	 * explanation : sending the data to the socket.							   *
	 *******************************************************************************/
	void sendData(string data);

	/*******************************************************************************
	 * function name : createSocket											       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : creating a socket in this connection.						   *
	 *******************************************************************************/
	void createSocket();

	/*******************************************************************************
	 * function name : connect												       *
	 * input : connect to a certain socket.									       *
	 * output : nothing.													       *
	 * explanation : sending the data to the socket.							   *
	 *******************************************************************************/
	void connect();

	/*******************************************************************************
	 * function name : getDataReceived										       *
	 * input : nothing.														       *
	 * output : the massage as string.										       *
	 * explanation : return the massage as string.								   *
	 *******************************************************************************/
	string getDataReceived();

	/*******************************************************************************
	 * function name : dataReceiver											       *
	 * input : nothing.														       *
	 * output : nothing.													       *
	 * explanation : receive the massage to the buffer.							   *
	 *******************************************************************************/
	void dataReceiver();
};

#endif /* UDPSERVER_H_ */
