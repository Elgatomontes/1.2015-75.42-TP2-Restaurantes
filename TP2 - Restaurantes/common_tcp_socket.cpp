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
#include <string.h>
#include <errno.h>

#include "common_tcp_socket.h"

using namespace std;

int TCPSocket::socketGetFileDescriptor() {
    return this->socketFd;
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

struct sockaddr_in TCPSocket::socketGetAddr(int port) {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(port);
    newAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
    return newAddr;
}

const string TCPSocket::socketReceive(size_t dataLength) {
	size_t sizeReceived = 0;
	string dataRecieved = "";

	while (sizeReceived < dataLength) {
		int result;
		string buffer;
		result = recv(this->socketFd, &buffer, dataLength, 0);

		if (result == SOCKET_ERROR) {
			perror("Socket recieve error");
			printf("Socket recieve error:%sn\n", strerror(errno));
			exit(1);
		}

		sizeReceived += result;
		dataRecieved += buffer;
		printf("Recibido: %s\n", buffer.c_str());
	}
	printf("Texto final recibido: %s\n", dataRecieved.c_str());

	return dataRecieved;
}

void TCPSocket::socketSend(const string data, size_t dataLength) {

}

void TCPSocket::socketShutDown(TCPSocketShutDownHow how) {
    if (shutdown(this->socketFd, how) == SOCKET_ERROR) {
        perror("Socket shutdown error");
        printf("Socket shutdown error:%sn\n", strerror(errno));
        exit(1);
    }
}
