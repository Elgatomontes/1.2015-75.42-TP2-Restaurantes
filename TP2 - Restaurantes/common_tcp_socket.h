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

using namespace std;

#define SOCKET_ERROR -1

typedef enum {
    TCPSocketShutDownHowReceiving = 0,
    TCPSocketShutDownHowTransmit = 1,
    TCPSocketShutDownHowBoth = 2
} TCPSocketShutDownHow;

class TCPSocket {
private:
    int socketFd;
    
protected:
    virtual struct sockaddr_in socketGetAddr(const string &address, int port);
    int socketGetFileDescriptor();
    
    
public:
    // Constructors and destructors.
    virtual ~TCPSocket();
    TCPSocket();
    
    int socketShutDown(TCPSocketShutDownHow how);
};

#endif /* defined(__TP2___Restaurantes__common_socket__) */
