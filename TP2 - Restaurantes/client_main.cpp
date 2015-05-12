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
#define SOCKET_PORT 4321

int main(int argc, const char * argv[]) {
    ClientSocket clientSocket;

    clientSocket.socketConnect(SOCKET_ADDRESS, SOCKET_PORT);

    std::string dataToSend("Reciví tu conexión\n");
    clientSocket.socketReceive(sizeof(dataToSend.c_str()));

    return 0;
}
