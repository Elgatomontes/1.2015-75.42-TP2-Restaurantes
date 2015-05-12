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

#define SERVER_PORT 43210
#define SERVER_BACKLOG 20

int main(int argc, const char * argv[]) {
	ServerSocket serverSockFd;
	serverSockFd.socketBind(SERVER_PORT);
	serverSockFd.socketListenConnections(SERVER_BACKLOG);
    
    // Esto va en un thread.
	int clientSocketFd = serverSockFd.socketAcceptConnection();
	std::string dataToSend = "Recibi tu conexion";
	serverSockFd.socketSend(clientSocketFd, dataToSend);
    serverSockFd.socketShutDown(TCPSocketShutDownHowBoth);
    
    return 0;
}
