//
//  common_thread.cpp
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#include "common_thread.h"

POSIXThread::~POSIXThread() {
}

POSIXThread::POSIXThread() {
    if (pthread_create(&this->thread, NULL, POSIXThread::threadFunction, this)) {
        
    }
}

void POSIXThread::join() {
}

void POSIXThread::runThread() {
}

void *POSIXThread::threadFunction(void *data) {
    return NULL;
}
