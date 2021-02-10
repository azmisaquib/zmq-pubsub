#include <cstring>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include "zmq/zmq.hpp"


int main( int argc, char *argv[] )
{
    zmq::context_t context ( 1 );
    zmq::socket_t publisher ( context, ZMQ_PUB );
    publisher.bind( "tcp://*:5556" );
    usleep( 1000000 );
    std::string msg = "test";

    // loop 100 times
    for ( int i = 1; i <= 100; i++ ) 
    {
        zmq::message_t request( msg.length() );
        memcpy( request.data(), msg.c_str(), msg.length() );
        publisher.send( request );
        std::cout << "sending: " << i << std::endl;
    }
}