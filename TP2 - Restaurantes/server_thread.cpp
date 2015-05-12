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
    delete this->threadList;
}

ServerThread::ServerThread(ServerSocket &socket)
: POSIXThread(), serverSocket(socket) {
    printf("Server Thread creado\n");
    this->threadList = new std::list<ProcessClientThread>;
}

void ServerThread::threadRun() {
    printf("Corriendo hilo para el accept del server\n");
    while (this->serverSocket.socketGetKeepTalking() == true) {
        printf("Estoy por aceptar una conexión en el loop\n");
        int clientSocketFd = this->serverSocket.socketAcceptConnection();
        TCPSocket clientSocket(clientSocketFd);
        ProcessClientThread *clientThread;
        clientThread = new ProcessClientThread(this->serverSocket, clientSocket);

        
        std::list<ProcessClientThread>::iterator it = this->threadList->end();
        this->threadList->insert(it, *clientThread);
        
        for (it = this->threadList->begin(); it != this->threadList->end(); it++) {
            ProcessClientThread thread = *it;
            
            thread.threadJoin();
            this->threadList->erase(it);
        }
        
        delete clientThread;
    }
    
    printf("SALÍ DEL WHILE :S\n");
}
