//
//  common_tcp_socket.h
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP2___Restaurantes__common_socket__
#define __TP2___Restaurantes__common_socket__

#include <stdio.h>
#include <string>

#define SOCKET_ERROR -1
#define SOCKET_CLOSE 0

typedef enum {
    TCPSocketShutDownHowReceiving = 0,
    TCPSocketShutDownHowTransmit = 1,
    TCPSocketShutDownHowBoth = 2
} TCPSocketShutDownHow;

class TCPSocket {
private:
    int socketFd;
    bool keepTalking;
    
protected:
    virtual struct sockaddr_in socketGetAddr(int port);
    int socketGetFileDescriptor();
    
public:
    // Constructors and destructors.
    virtual ~TCPSocket();
    TCPSocket();
    TCPSocket(int socketFd);
    
    // Getters and setters.
    void socketSetKeepTalking(bool keepTalking);
    bool socketGetKeepTalking();
    
    const std::string socketReceive(size_t dataLength);
    void socketSend(const std::string &data);
    void socketShutDown(TCPSocketShutDownHow how);
};

#endif /* defined(__TP2___Restaurantes__common_socket__) */
