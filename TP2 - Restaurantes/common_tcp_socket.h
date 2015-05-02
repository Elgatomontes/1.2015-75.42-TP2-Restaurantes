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
    string socketAddress;
    int portNumber;
    int socketFd;
    
public:
    // Constructors and destructors.
    virtual ~TCPSocket();
    TCPSocket(string const &address, int portNumber);
};

#endif /* defined(__TP2___Restaurantes__common_socket__) */
