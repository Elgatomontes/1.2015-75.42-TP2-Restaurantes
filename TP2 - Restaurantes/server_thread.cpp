//
//  server_thread.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "server_process_client_thread.h"
#include "common_tcp_socket.h"
#include "server_thread.h"

ServerThread::~ServerThread() {
    
}

void ServerThread::threadRun() {
    printf("Corriendo hilo para el accept del server\n");
    while (this->serverSocket.socketGetKeepTalking() == true) {
        printf("Estoy por aceptar una conexión en el loop\n");
        int clientSocketFd = this->serverSocket.socketAcceptConnection();
        TCPSocket clientSocket(clientSocketFd);
        ProcessClientThread clientThread(this->serverSocket, clientSocket);
        clientThread.threadJoin();
    }
}
