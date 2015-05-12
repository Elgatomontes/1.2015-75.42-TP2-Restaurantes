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
#include "server_thread.h"

#define SERVER_PORT 43210
#define SERVER_BACKLOG 20

int main(int argc, const char * argv[]) {
	ServerSocket serverSock;
	serverSock.socketBind(SERVER_PORT);
	serverSock.socketListenConnections(SERVER_BACKLOG);
    
    ServerThread serverThread(serverSock);
    serverThread.runThread();
//    // Esto va en un thread.
//    int clientSocketFd = serverSockFd.socketAcceptConnection();
//    std::string dataToSend = "Recibi tu conexion";
//    serverSockFd.socketSend(clientSocketFd, dataToSend);
//    serverSockFd.socketShutDown(TCPSocketShutDownHowBoth);
    
    char inputChar;
    std::cin >> inputChar;
    
    while (inputChar != 'q') {
        std::cin >> inputChar;
    }
    
    if (inputChar == 'q') {
        serverSock.socketSetKeepTalking(false);
        serverSock.socketShutDown(TCPSocketShutDownHowBoth);
    }
    
    serverThread.join();
    
    return 0;
}
