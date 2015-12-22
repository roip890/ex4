//main.cpp

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include "MoviesSystem.h"
#include "gtest.h"


using namespace std;
GTEST_API_ int main(int argc, char* argv[]) {
	printf("Running main() from main.cpp\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();


	TcpConnection UdpCon = new TcpConnection("127.0.0.1", 5555);

	UdpCon.sendToSocket("hello");
	UdpCon.receiveFromSocket();
	UdpCon.getBuffer();
	UdpCon.closeSocket();

	TcpConnection TcpCon = new TcpConnection("127.0.0.1", 5555);

	TcpCon.sendToSocket("hello");
	TcpCon.receiveFromSocket();
	TcpCon.getBuffer();
	TcpCon.closeSocket();


    return 0;
}
