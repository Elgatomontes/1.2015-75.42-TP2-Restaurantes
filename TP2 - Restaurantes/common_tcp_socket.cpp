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

TCPSocket::TCPSocket(int socketFd) {
    keepTalking = true;
    this->socketFd = socketFd;
}

TCPSocket::TCPSocket() {
    keepTalking = true;
	if ((socketFd = socket(AF_INET,SOCK_STREAM,0)) == SOCKET_ERROR) {
		perror("Socket creation error");
		printf("Socket creation error: %sn\n", strerror(errno));
        keepTalking = false;
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
    bool socketOpen = true;
    
    while (receivedData < dataLength && socketOpen == true) {
        int result;
        std::vector<char> buffer;
        buffer.resize(dataLength - receivedData, 0);
        
        result = recv(this->socketFd, &(buffer[0]), dataLength, 0);
        
        if (result == SOCKET_ERROR) {
            perror("Socket receive error");
            printf("Socket receive error: %sn\n", strerror(errno));
            exit(1);
        } else if (result == SOCKET_CLOSE) {
            perror("Socket receive close");
            printf("Socket receive close: %sn\n", strerror(errno));
            socketOpen = false;
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

void TCPSocket::socketSend(const std::string &data) {
	size_t sendData = 0;
	size_t dataSize = data.size();
    bool socketOpen = true;

	while(sendData < dataSize && socketOpen == true) {
		int result = send(this->socketFd, data.c_str(), dataSize, 0);

		if (result == SOCKET_ERROR) {
			perror("Socket send error");
			printf("Socket send error: %sn\n", strerror(errno));
			exit(1);
        } else if (result == SOCKET_CLOSE) {
            perror("Socket receive close");
            printf("Socket receive close: %sn\n", strerror(errno));
            socketOpen = false;
        }

		sendData += result;
		printf("Datos parciales enviados: %lu/%lu\n", sendData, dataSize);
	}

	printf("Datos enviados: %lu/%lu cuyo texto: %s\n", sendData, dataSize, data.c_str());
}

void TCPSocket::socketShutDown(TCPSocketShutDownHow how) {
    this->keepTalking = false;
	if (shutdown(this->socketFd, how) == SOCKET_ERROR) {
		perror("Socket shutdown error");
		printf("Socket shutdown error: %sn\n", strerror(errno));
		exit(1);
	}
	printf("Socket shutDown\n");
}

void TCPSocket::socketSetKeepTalking(bool keepTalking) {
    this->keepTalking = keepTalking;
}

bool TCPSocket::socketGetKeepTalking() {
    return this->keepTalking;
}
