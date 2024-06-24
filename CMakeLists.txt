cmake_minimum_required(VERSION 3.10)
project(HelloWorldGRPC)

find_package(gRPC CONFIG REQUIRED)
find_package(Protobuf CONFIG REQUIRED)
find_package(SQLite3 REQUIRED)

set(CMAKE_CXX_STANDARD 11)

add_executable(server server.cpp helloworld.pb.cc helloworld.grpc.pb.cc)
target_link_libraries(server gRPC::grpc++ gRPC::grpc++_reflection protobuf::libprotobuf)

add_executable(client client.cpp helloworld.pb.cc helloworld.grpc.pb.cc)
target_link_libraries(client gRPC::grpc++ gRPC::grpc++_reflection protobuf::libprotobuf SQLite::SQLite3)
