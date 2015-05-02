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

class TCPSocket {
private:
    int socketFd;
    
protected:
    virtual struct sockaddr_in socketAddr(string const &address, int port);
    
    
public:
    // Constructors and destructors.
    virtual ~TCPSocket();
    TCPSocket();
    
    void bindSocket(string const &address, int port);
    void listenConnections(int backlog); // @TODO: Gastón - Esto es solo para el server.
};

#endif /* defined(__TP2___Restaurantes__common_socket__) */
