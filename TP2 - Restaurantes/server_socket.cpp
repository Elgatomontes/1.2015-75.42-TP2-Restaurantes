//
//  server_socket.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "server_socket.h"

ServerSocket::~ServerSocket() {
}

void ServerSocket::socketBind(int port) {
    struct sockaddr_in addr_in = socketGetAddr(port);
    int socketFd = socketGetFileDescriptor();
    int result = bind(socketFd, (struct sockaddr *)&addr_in, sizeof(addr_in));
    if (result == SOCKET_ERROR) {
        perror("Socket bind error");
        printf("Socket bind error:%sn\n", strerror(errno));
        exit(1);
    }

    printf("Bindeado al puerto: %d\n", port);
}

void ServerSocket::socketListenConnections(int backlog) {
    if (listen(socketGetFileDescriptor(), backlog) == SOCKET_ERROR) {
        perror("Socket listen error");
        printf("Socket listen error:%sn\n", strerror(errno));
        exit(1);
    }

    printf("Escuchando conexiones...\n");
}

int ServerSocket::socketAcceptConnection() {
    socklen_t socketLength = sizeof(struct sockaddr_in);
    int socketFd = socketGetFileDescriptor();
    struct sockaddr_in *addr;
    
    clientFd = accept(socketFd, (struct sockaddr *)&addr, &socketLength);
    
    if (clientFd == SOCKET_ERROR) {
        perror("Socket accept error");
        printf("Socket accept error:%sn\n", strerror(errno));
        exit(1);
    }
    
    printf("Conexión entrante acceptada\n");

    return clientFd;
}

struct sockaddr_in ServerSocket::socketGetAddr(int port) {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(port);
    newAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
    return newAddr;
}
