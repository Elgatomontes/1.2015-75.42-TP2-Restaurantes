//
//  client_main.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "client_socket.h"

#define SOCKET_ADDRESS "127.0.0.1"
#define SOCKET_PORT 43210

int main(int argc, const char * argv[]) {
    ClientSocket clientSocket;
    clientSocket.socketConnect(SOCKET_ADDRESS, SOCKET_PORT);
    std::string dataToSend = "Recibi tu conexion";
    clientSocket.socketReceive(dataToSend.size());
    clientSocket.socketShutDown(TCPSocketShutDownHowBoth);
    return 0;
}
