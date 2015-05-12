//
//  server_process_client_thread.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "server_process_client_thread.h"

ProcessClientThread::~ProcessClientThread() {
    
}

void ProcessClientThread::threadRun() {
    printf("Corriendo hilo para el send del server/client\n");
    std::string dataToSend = "Recibi tu conexion";
    this->clientSocket.socketSend(dataToSend);
    printf("Envíe correctamente los datos\n");
    this->serverSocket.socketGetKeepTalking();
}
