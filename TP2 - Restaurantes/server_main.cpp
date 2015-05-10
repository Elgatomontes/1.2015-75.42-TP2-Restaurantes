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

	printf("Bindeando al puerto: %d\n", SERVER_PORT);
	serverSockFd.socketBind(SERVER_PORT);

	printf("Escuchando conexiones...\n");
	serverSockFd.socketListenConnections(SERVER_BACKLOG);

	printf("Aceptando conexiones...\n");
	int clientSocketFd = serverSockFd.socketAcceptConnection();

	printf("Enviando datos...\n");
	serverSockFd.socketSend(clientSocketFd, "Reciví tu conexión\n");

    return 0;
}
