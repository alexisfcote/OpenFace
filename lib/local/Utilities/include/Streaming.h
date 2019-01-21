#ifndef __STREAMING__
#define __STREAMING__

#include <string>
#include <iostream>
#include <winsock.h>

#pragma comment(lib, "Ws2_32.lib")

namespace streaming {
	class Streaming
	{
		WSADATA WSAData;
		SOCKADDR_IN serverAddr;
		SOCKET server = INVALID_SOCKET;

	public:
		Streaming();
		~Streaming();
		
		bool isOpen = FALSE;
		int Streaming::init(int port);
		int SendMsg(std::string msg);

	private:
	};

}
#endif // __STREAMING__
