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
    delete this->acceptedThreadList;
}

ServerThread::ServerThread(ServerSocket &socket)
: POSIXThread(), serverSocket(socket) {
    printf("Server Thread creado\n");
    this->acceptedThreadList = new std::list<ProcessClientThread>;
}

void ServerThread::threadRun() {
    printf("Corriendo hilo para el accept del server\n");
    while (this->serverSocket.socketGetKeepTalking() == true) {
        printf("Estoy por aceptar una conexión en el loop\n");
        int clientSocketFd = this->serverSocket.socketAcceptConnection();
        TCPSocket *clientSocket = new TCPSocket(clientSocketFd);
        ProcessClientThread *clientThread;
        clientThread = new ProcessClientThread(this->serverSocket, *clientSocket);
//
//        std::list<ProcessClientThread>::iterator it;
//        it = this->acceptedThreadList->end();
//        this->acceptedThreadList->insert(it, *clientThread);
//        
//        clientThread->threadJoin();
//
//        for (it = this->acceptedThreadList->begin(); it != this->acceptedThreadList->end(); it++) {
//            ProcessClientThread thread = *it;
//            thread.threadJoin();
//        }
//        
//        delete clientThread;
    }
    
    printf("SALÍ DEL WHILE :S\n");
}
