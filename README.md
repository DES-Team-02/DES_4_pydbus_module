# Vehicle Control System

This project implements a vehicle control system using D-Bus and C++ on Ubuntu. It provides a DBus interface to control and monitor a vehicle's steering and speed via D-Bus messages.

## Prerequisites

Before you can build and run this project, you need to install the necessary dependencies and set up your environment.

### Dependencies

Install the necessary C++ and D-Bus development libraries:

```bash
sudo apt update
sudo apt install build-essential libdbus-1-dev libdbus-c++-dev
```

Generating Proxy Classes from XML
To generate C++ proxy classes from your DBus XML interface definition, use the dbusxx-xml2cpp tool:
```bash
dbusxx-xml2cpp vehicle_control.xml --proxy=vehicle_control_proxy.h
```

This command generates a header file vehicle_control_proxy.h, which is included in the source files to interact with the DBus interface.


Compilation
Compile the project using g++ and the flags provided by pkg-config:

```bash
g++ -o vehicle_control main_subscribe.cpp `pkg-config --cflags --libs dbus-c++-1`
```
This command compiles main_subscribe.cpp, linking against the necessary libraries, and produces an executable named vehicle_control.


Running the Application
Run the executable in a terminal:

```bash
./vehicle_control
```
Ensure that the DBus system is properly configured and that your user has the necessary permissions to interact with DBus.

Project Structure
vehicle_control.xml: XML file describing the DBus interface.
vehicle_control_proxy.h: Generated proxy class from the XML interface.
main_subscribe.cpp: Main application source file that sets up the DBus connection and listens for signals.