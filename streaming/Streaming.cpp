#include "streaming.h"

// Streaming.cpp : Defines the entry point for the console application.
//
namespace streaming {
	Streaming::Streaming()
	{
	}

	Streaming::~Streaming()
	{
		closesocket(server);
		WSACleanup();
	}

	int Streaming::init(int port) {
		int iResult = WSAStartup(MAKEWORD(2, 2), &WSAData);
		if (iResult != NO_ERROR) {
			wprintf(L"WSAStartup failed with error: %d\n", iResult);
			return 1;
		}
		if (LOBYTE(WSAData.wVersion) != 2 || HIBYTE(WSAData.wVersion) != 2) {
			/* Tell the user that we could not find a usable */
			/* WinSock DLL.                                  */
			printf("Could not find a usable version of Winsock.dll\n");
			WSACleanup();
			return 1;
		}
		else
			printf("The Winsock 2.2 dll was found okay\n");

		server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
		if (server == INVALID_SOCKET) {
			wprintf(L"socket function failed with error: %u\n", WSAGetLastError());
			WSACleanup();
			return 1;
		}

		serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		serverAddr.sin_family = AF_INET;
		serverAddr.sin_port = htons(port);

		isOpen = TRUE;

		return 0;
	}

	int Streaming::SendMsg(std::string msg) {
		std::cout << "Sending connections..." << std::endl;
		const char *cstr = msg.c_str();

		int iResult = sendto(server, cstr, (int)msg.length(), 0, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
		if (iResult == SOCKET_ERROR) {
			wprintf(L"send failed with error: %d\n", WSAGetLastError());
			closesocket(server);
			WSACleanup();
			return 1;
		}
		std::cout << "Sent : " << msg << std::endl;
		return 0;
	}


	int main()
	{
		return 0;
	}
}