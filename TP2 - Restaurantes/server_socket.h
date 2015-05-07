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
    struct sockaddr_in socketGetAddr(const string &address, int port);

public:
    // Constructors and destructors.
    virtual ~ServerSocket();
    ServerSocket() : TCPSocket() {};
    
    // Sockets functions.
    void socketBind(const string &address, int port);
    void socketListenConnections(int backlog);
    int socketAcceptConnection();
};

#endif /* defined(__TP2___Restaurantes__server_socket__) */
