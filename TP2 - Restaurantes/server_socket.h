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

public:
    // Constructors and destructors.
    virtual ~ServerSocket();
    ServerSocket() : TCPSocket() {};
    
    void listenConnections(int backlog);
};

#endif /* defined(__TP2___Restaurantes__server_socket__) */
