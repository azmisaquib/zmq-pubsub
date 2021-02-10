# ZMQ Pub-Sub

This is a simple project that shows how to use ZeroMQ's Pub-Sub to communicate between two programs.
pubish.cpp opens and binds to the pub port and sends out 100 messages.
subscribe.cpp subscribes to the port and prints out messages that it receives.

[ZMQ C++](https://github.com/zeromq/cppzmq).


## Bootstrap

Bootstrap script to install ZeroMQ is included for Ubuntu 18

## Building the Program

Cmake has been included so you can build the project simply:

```bash
❯ rm -rf build && mkdir build
❯ cd build
❯ cmake ..
❯ make
```

## Running the Program

After building the program, it will create the *publish* and *subscribe* binaries in the build directory

Firstly, in one terminal run the subscribe program

```bash
❯ sudo ./subscribe
```

Then, in another terminal run the publish program

```bash
❯ sudo ./publish
```
