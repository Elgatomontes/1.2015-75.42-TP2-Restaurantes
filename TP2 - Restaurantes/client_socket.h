//
//  client_socket.h
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/2/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP2___Restaurantes__client_socket__
#define __TP2___Restaurantes__client_socket__

#include <stdio.h>

#include "common_tcp_socket.h"

class ClientSocket : public TCPSocket {
protected:
    struct sockaddr_in socketGetAddr(int port);
    
public:
    // Constructors and destructors.
    virtual ~ClientSocket();
    ClientSocket() : TCPSocket() {};
    
    void socketConnect(const string address, int port);
};

#endif /* defined(__TP2___Restaurantes__client_socket__) */
