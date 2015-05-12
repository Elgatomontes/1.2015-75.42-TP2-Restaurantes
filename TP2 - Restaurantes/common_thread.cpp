//
//  common_thread.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include <stdlib.h>
#include <errno.h>
#include <string>

#include "common_thread.h"

#define POSIX_THREAD_SUCCESS 0

POSIXThread::~POSIXThread() {
    pthread_exit(NULL);
}

POSIXThread::POSIXThread() {
    int res = pthread_create(&this->thread, NULL, POSIXThread::routine, this);

    if (res != POSIX_THREAD_SUCCESS) {
        perror("Thread create error");
        printf("Thread create error:%sn\n", strerror(errno));
        exit(1);
    }
}

void POSIXThread::join() {
    int res = pthread_join(this->thread, NULL);
    
    if (res != POSIX_THREAD_SUCCESS) {
        perror("Thread join error");
        printf("Thread join error:%sn\n", strerror(errno));
        exit(1);
    }
}

void POSIXThread::runThread() {
}

void *POSIXThread::routine(void *data) {
    POSIXThread *thread = (POSIXThread *)data;
    thread->runThread();
    return NULL;
}
