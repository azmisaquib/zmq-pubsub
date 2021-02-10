cmake_minimum_required( VERSION 3.2 )
link_directories(/usr/local/lib)
project( subscribe C CXX )
project( publish C CXX )

add_executable( subscribe subscribe.cpp )
add_executable( publish publish.cpp )

target_link_libraries( subscribe zmq )
target_link_libraries( publish zmq )

install(
    TARGETS subscribe publish
    DESTINATION ${PROJECT_SOURCE_DIR}
)
