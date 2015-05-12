//
//  server_thread.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "common_tcp_socket.h"
#include "server_thread.h"

ServerThread::~ServerThread() {
    
}
void ServerThread::runThread() {
    while (this->serverSocket.socketGetKeepTalking() == true) {
        int clientSocketFd = this->serverSocket.socketAcceptConnection();
        TCPSocket clientSocket(clientSocketFd);
        
        // @TODO: Gastón - Esto es un thread aparte.
        std::string dataToSend = "Recibi tu conexion";
        clientSocket.socketSend(dataToSend);
    }
}
