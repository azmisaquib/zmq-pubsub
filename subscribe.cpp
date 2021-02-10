// Created By Saquib Azmi on 11/02/2021
#include <iostream>
#include <string>
#include "zmq/zmq.hpp"


int main( int argc, char *argv[] )
{
    // Create ZMQ Context
    zmq::context_t context ( 1 );
    // Create the Subscribe socket
    zmq::socket_t subscriber ( context, ZMQ_SUB );
    // Connect to a tcp socket
    subscriber.connect( "tcp://localhost:5556" );
    // Set the socket option to subscribe
    subscriber.setsockopt( ZMQ_SUBSCRIBE, "", 0 );

    // infinite loop to receive messages
    for ( int i = 1; i > 0; i++ )
    {
        // Receive the message and convert to string
        zmq::message_t update;
        subscriber.recv( &update );
        std::string msg = update.to_string();
        // Print the message
        std::cout << "Num: " << i << ", message: " << msg << std::endl;
    }

}