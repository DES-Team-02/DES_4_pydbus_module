cmake_minimum_required(VERSION 3.0)
project(Jetson LANGUAGES CXX C)                         

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

### PACKAGES ###
find_package(CommonAPI REQUIRED)
find_package(CommonAPI-SomeIP REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(DBUSCXX REQUIRED dbus-c++-1)

# APP_INFO
set(APP_PACKAGE_NAME commonapi)
set(MAJOR_VERSION 0)
set(MINOR_VERSION 1)

include_directories(
  ./include
  ./src-gen/core
  ./src-gen/someip
  ${COMMONAPI_INCLUDE_DIRS}
  ${COMMONAPI_SOMEIP_INCLUDE_DIRS}
  ${DBUSCXX_INCLUDE_DIRS}
)

add_executable(jetson
	src/main.cpp
	src/JetsonStubImpl.cpp
  src/VehicleControlProxyImpl.cpp
)
target_link_libraries(jetson CommonAPI ${DBUSCXX_LIBRARIES})

set(INTERFACE "someip/v${MAJOR_VERSION}/${APP_PACKAGE_NAME}")
add_library(JetsonStub SHARED
  src-gen/${INTERFACE}/JetsonSomeIPDeployment.cpp
  src-gen/${INTERFACE}/JetsonSomeIPStubAdapter.cpp
)
target_link_libraries(JetsonStub CommonAPI-SomeIP)

add_library(JetsonProxy SHARED
  src-gen/${INTERFACE}/JetsonSomeIPDeployment.cpp
  src-gen/${INTERFACE}/JetsonSomeIPProxy.cpp
)
target_link_libraries(JetsonProxy CommonAPI-SomeIP)