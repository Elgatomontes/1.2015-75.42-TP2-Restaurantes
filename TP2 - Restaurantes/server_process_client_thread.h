//
//  server_process_client_thread.h
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP2___Restaurantes__server_process_client_thread__
#define __TP2___Restaurantes__server_process_client_thread__

#include <stdio.h>

#include "common_tcp_socket.h"
#include "common_thread.h"

class ProcessClientThread : public POSIXThread {
private:
    TCPSocket &serverSocket;
    TCPSocket &clientSocket;
    
public:
    // Constructors and destructors.
    virtual ~ProcessClientThread();
    ProcessClientThread(TCPSocket &server, TCPSocket &client)
    : POSIXThread(), serverSocket(server), clientSocket(client) {
        printf("Server proccess Thread creado\n");
    }
    
    void threadRun();
};

#endif /* defined(__TP2___Restaurantes__server_process_client_thread__) */
