// Created By Saquib Azmi on 11/02/2021
#include <iostream>
#include <string>
#include <unistd.h>
#include "zmq/zmq.hpp"


int main( int argc, char *argv[] )
{
    // Create ZMQ Context
    zmq::context_t context ( 1 );
    // Create the Publish socket
    zmq::socket_t publisher ( context, ZMQ_PUB );
    // Bind to a tcp socket
    publisher.bind( "tcp://*:5556" );
    // Sleep for 1 sec, if this sleep is removed, you may lose some initial messages while it is being binded
    usleep( 1000000 );
    // Message to send to the subscribers
    std::string msg = "test";

    // loop 100 times
    for ( int i = 1; i <= 100; i++ ) 
    {
        // Create zmq message
        zmq::message_t request( msg.length() );
        // Copy contents to zmq message
        memcpy( request.data(), msg.c_str(), msg.length() );
        // Publish the message
        publisher.send( request );
        std::cout << "sending: " << i << std::endl;
    }
}