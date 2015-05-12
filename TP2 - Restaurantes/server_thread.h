//
//  server_thread.h
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP2___Restaurantes__server_thread__
#define __TP2___Restaurantes__server_thread__

#include <stdio.h>
#include <list>

#include "server_process_client_thread.h"
#include "common_thread.h"
#include "server_socket.h"

class ServerThread : public POSIXThread {
private:
    ServerSocket &serverSocket;
    std::list<ProcessClientThread> *acceptedThreadList;
    
public:
    // Constructors and destructors.
    virtual ~ServerThread();
    ServerThread(ServerSocket &socket);
    
    void threadRun();
};

#endif /* defined(__TP2___Restaurantes__server_thread__) */
