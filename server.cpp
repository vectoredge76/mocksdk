#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using helloworld::HelloWorldService;
using helloworld::HelloRequest;
using helloworld::HelloResponse;
using helloworld::HelloMessage;
using helloworld::AckMessage;

class HelloWorldServiceImpl final : public HelloWorldService::Service {
public:
    Status SayHello(ServerContext* context, const HelloRequest* request, HelloResponse* response) override {
        response->set_message("Hello");
        return Status::OK;
    }

    Status ReceiveHello(ServerContext* context, const HelloMessage* request, AckMessage* response) override {
        std::cout << "Received from client: " << request->message() << std::endl;
        response->set_message("Received");
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    HelloWorldServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}
