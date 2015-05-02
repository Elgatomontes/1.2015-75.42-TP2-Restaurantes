//
//  common_socket.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>

#include "common_tcp_socket.h"

using namespace std;

#define SOCKET_ERROR -1

TCPSocket::~TCPSocket() {
    this->socketAddress = nullptr;
    this->portNumber    = 0;
}

TCPSocket::TCPSocket(string const &address, int portNumber) {
    this->socketAddress = address;
    this->portNumber    = portNumber;
    
    if ((socketFd = socket(AF_INET,SOCK_STREAM,0)) == SOCKET_ERROR) {
        perror("Socket creatino error\n");
        exit(1);
    }
}
