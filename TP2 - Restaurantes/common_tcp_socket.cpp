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
#include <vector>

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
	return newAddr;
}

const std::string TCPSocket::socketReceive(size_t dataLength) {
	printf("Data to receive length: %lu\n", dataLength);
    size_t receivedData = 0;
    std::string dataReceived;
    
    while (receivedData < dataLength) {
        int result;
        std::vector<char> buffer;
        buffer.resize(dataLength - receivedData, 0);
        
        result = recv(this->socketFd, &(buffer[0]), dataLength, 0);
        
        if (result == SOCKET_ERROR) {
            perror("Socket receive error");
            printf("Socket receive error:%sn\n", strerror(errno));
            exit(1);
        }
        
        receivedData += result;
        std::string bufferStr(buffer.begin(), buffer.end());
        std::string acumStr(dataReceived.c_str());
        dataReceived = acumStr + bufferStr;
        
        printf("Datos parciales recibidos: %lu/%lu Texto: %s\n", receivedData, dataLength, bufferStr.c_str());
        printf("Acumulado: %s\n", dataReceived.c_str());
    }
    
    printf("Datos recibidos: %s\n", dataReceived.c_str());
    return dataReceived;
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

	printf("Datos enviados: %lu/%lu cuyo texto: %s\n", sendData, dataSize, data.c_str());
}

void TCPSocket::socketShutDown(TCPSocketShutDownHow how) {
	if (shutdown(this->socketFd, how) == SOCKET_ERROR) {
		perror("Socket shutdown error");
		printf("Socket shutdown error:%sn\n", strerror(errno));
		exit(1);
	}
	printf("Socket shutDown\n");
}
