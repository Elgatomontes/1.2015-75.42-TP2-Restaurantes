//
//  common_socket.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

#include "common_tcp_socket.h"

using namespace std;

#define SOCKET_ERROR -1

TCPSocket::~TCPSocket() {
}

TCPSocket::TCPSocket() {
    if ((socketFd = socket(AF_INET,SOCK_STREAM,0)) == SOCKET_ERROR) {
        perror("Socket creation error");
        printf("Socket creation error:%sn\n", strerror(errno));
        exit(1);
    }
}

void TCPSocket::initSocketAddr(string const &address, int portNumber) {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(portNumber);
    newAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(newAddr.sin_zero), '\0', 8);
}

void TCPSocket::bindSocket(string const &address, int portNumber) {
    this->initSocketAddr(address, portNumber);
}
