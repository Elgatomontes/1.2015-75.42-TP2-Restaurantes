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
#include <unistd.h>
#include <errno.h>

#include "common_tcp_socket.h"

using namespace std;

int TCPSocket::getSocketFileDescriptor() {
    return socketFd;
}

TCPSocket::~TCPSocket() {
    close(this->socketFd);
    this->socketFd = 0;
}

TCPSocket::TCPSocket() {
    if ((socketFd = socket(AF_INET,SOCK_STREAM,0)) == SOCKET_ERROR) {
        perror("Socket creation error");
        printf("Socket creation error:%sn\n", strerror(errno));
        exit(1);
    }
}

struct sockaddr_in TCPSocket::socketAddr(const string &address, int port) {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(port);
    newAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
    return newAddr;
}

int TCPSocket::shutDownSocket(TCPSocketShutDownHow how) {
    int result = shutdown(this->socketFd, how);
    if (result == SOCKET_ERROR) {
        perror("Socket shutdown error");
        printf("Socket shutdown error:%sn\n", strerror(errno));
        return SOCKET_ERROR;
    }
    return result;
}
