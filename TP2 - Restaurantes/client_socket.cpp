//
//  client_socket.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string>

#include "client_socket.h"

ClientSocket::~ClientSocket() {
}

struct sockaddr_in ClientSocket::socketGetAddr(int port) {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(port);
    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
    return newAddr;
}

void ClientSocket::socketConnect(const std::string address, int port) {
    struct sockaddr_in server_addr = socketGetAddr(port);
    inet_pton(AF_INET, address.c_str(), &server_addr.sin_addr);
    
    struct sockaddr *addr = (struct sockaddr *)&server_addr;
    socklen_t addr_size = sizeof(struct sockaddr);
    
    if (connect(socketGetFileDescriptor(), addr, addr_size) == SOCKET_ERROR) {
        perror("Socket listen error");
        printf("Socket listen error:%sn\n", strerror(errno));
        exit(1);
    }

    printf("Se conectó correctamente a la dirección: %s y puerto %d\n", address.c_str(), port);
}
