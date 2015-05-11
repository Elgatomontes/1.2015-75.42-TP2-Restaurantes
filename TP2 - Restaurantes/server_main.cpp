//
//  server_main.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <strings.h>
#include <string>

#include "server_socket.h"

#define SERVER_PORT 4321
#define SERVER_BACKLOG 20

int main(int argc, const char * argv[]) {
	ServerSocket serverSockFd;

	serverSockFd.socketBind(SERVER_PORT);
	serverSockFd.socketListenConnections(SERVER_BACKLOG);
	int clientSocketFd = serverSockFd.socketAcceptConnection();
	std::string dataToSend = "Reciví tu conexión\n";
	serverSockFd.socketSend(clientSocketFd, dataToSend);

    return 0;
}
