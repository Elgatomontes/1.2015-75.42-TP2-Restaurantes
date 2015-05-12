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
#include <string>

#include "common_tcp_socket.h"

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

const std::string TCPSocket::socketReceive(size_t dataLength) {
	printf("Data to receive length: %lu\n", dataLength);
	char *buffer = new char(dataLength);
	int result;

	result = recv(this->socketFd, buffer, dataLength, 0);

	if (result == SOCKET_ERROR) {
		perror("Socket send error");
		printf("Socket send error:%sn\n", strerror(errno));
		delete(buffer);
		exit(1);
	}

	printf("Lala\n");
	std::string dataReceive(buffer);

	delete(buffer);

	printf("Datos recibidos: %s", dataReceive.c_str());

	return dataReceive;
}

void TCPSocket::socketSend(int socketDest, const std::string &data) {
	size_t sendData = 0;
	size_t dataSize = data.size();

	while(sendData < dataSize) {
		int result = send(socketDest, data.c_str(), dataSize, 0);

		if (result == SOCKET_ERROR) {
			perror("Socket send error");
			printf("Socket send error:%sn\n", strerror(errno));
			exit(1);
		}

		sendData += result;
		printf("Datos parciales enviados: %lu/%lu\n", sendData, dataSize);
	}

	printf("Datos enviados: %lu/%lu cuyo texto: %s", sendData, dataSize, data.c_str());
}

void TCPSocket::socketShutDown(TCPSocketShutDownHow how) {
	if (shutdown(this->socketFd, how) == SOCKET_ERROR) {
		perror("Socket shutdown error");
		printf("Socket shutdown error:%sn\n", strerror(errno));
		exit(1);
	}
}
