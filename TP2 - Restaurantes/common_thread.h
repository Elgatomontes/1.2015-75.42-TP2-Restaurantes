//
//  common_thread.h
//  TP2 - Restaurantes
//
//  Created by Gastón Montes on 5/12/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef __TP2___Restaurantes__common_thread__
#define __TP2___Restaurantes__common_thread__

#include <stdio.h>
#include <pthread.h>

class POSIXThread {
private:
    pthread_t thread;
    
    static void *routine(void *data);
    
public:
    // Constructors and destructors.
    virtual ~POSIXThread();
    POSIXThread();
    
    void threadJoin();
    virtual void threadRun();
};

#endif /* defined(__TP2___Restaurantes__common_thread__) */
