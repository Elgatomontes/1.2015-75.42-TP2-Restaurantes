//
//  server_thread.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "server_thread.h"

ServerThread::~ServerThread() {
    
}
void ServerThread::runThread() {
    while (this->serverSocket.socketGetKeepTalking() == true) {
        int clientSocketFd = this->serverSocket.socketAcceptConnection();
        std::string dataToSend = "Recibi tu conexion";
        this->serverSocket.socketSend(clientSocketFd, dataToSend);
    }
}
