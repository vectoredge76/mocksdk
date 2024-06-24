#include <iostream>
#include <memory>
#include <string>
#include <sqlite3.h>

#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::HelloWorldService;
using helloworld::HelloRequest;
using helloworld::HelloResponse;
using helloworld::HelloMessage;
using helloworld::AckMessage;

