//
//  server_socket.h
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP2___Restaurantes__server_socket__
#define __TP2___Restaurantes__server_socket__

#include <stdio.h>

#include "common_tcp_socket.h"

class ServerSocket : public TCPSocket {
private:
    int clientFd;
    
protected:
    struct sockaddr_in socketGetAddr(int port);

public:
    // Constructors and destructors.
    virtual ~ServerSocket();
    ServerSocket() : TCPSocket() {
    	clientFd = 0;
    };
    
    // Sockets functions.
    void socketBind(int port);
    void socketListenConnections(int backlog);
    int socketAcceptConnection();
};

#endif /* defined(__TP2___Restaurantes__server_socket__) */
