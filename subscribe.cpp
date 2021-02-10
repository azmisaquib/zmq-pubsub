#include <cstring>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <chrono>
#include <thread>
#include "zmq/zmq.hpp"


int main( int argc, char *argv[] )
{
    zmq::context_t context ( 1 );
    zmq::socket_t subscriber ( context, ZMQ_SUB );
    subscriber.connect( "tcp://localhost:5556" );
    subscriber.setsockopt( ZMQ_SUBSCRIBE, "", 0 );

    // infinite loop to receive messages
    for ( int i = 1; i > 0; i++ )
    {
        zmq::message_t update;
        subscriber.recv( &update );
        std::string msg = update.to_string();
        std::cout << "Num: " << i << ", message: " << msg << std::endl;
    }

}