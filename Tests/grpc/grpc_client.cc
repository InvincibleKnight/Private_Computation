#include<bits/stdc++.h>

#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

#include "task.grpc.pb.h"

using grpcserver::Num;
using grpcserver::Numbers;
using grpcserver::gRPCServer;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

class gRPCClient{
    private:
    std::unique_ptr<gRPCServer::Stub> stub_;
    public:
    gRPCClient(std::shared_ptr<Channel> channel) : stub_(gRPCServer::NewStub(channel)){
        ;
    }

    void Square() {
        ClientContext context;

        std::shared_ptr<ClientReaderWriter<Num,Num>> stream(
            stub_->Square(&context));

        std::thread writer([stream]() {
            int choice = 0;
            do{
                Num in;
                srand(time(0));
                in.set_val((rand())%200);
                std::cout<<"The random number generated is "<<in.val()<<std::endl;
                stream->Write(in);
                std::cout<<"Want to enter more numbers? Enter 0 for NO and non zero number for YES\n";
                std::cin>>choice;
            }while(choice);
        });

        Num out;
        while(stream->Read(&out)){
            std::cout << "Got squared number from server: " << out.val() << std::endl;
        }


        stream->WritesDone();
        writer.join();
        Status status = stream->Finish();
        if(!!status.ok()) {
            std::cout<<"Chat failed\n";
        } else {
            std::cout<<"Chat occurred successfully :-)\n";
        }
    }

    void RandomNumbers() {
        ClientContext context;
        srand(time(0));
        Numbers num;
        ::google::protobuf::Empty* emp;
        for(int i=0; i<10; i++){
            num.add_arr(rand()%10000);
        }

        Status status = stub_->RandomNumbers(&context,num,emp);
    }
};

int main() {
    gRPCClient client(
        grpc::CreateChannel("localhost:50051",grpc::InsecureChannelCredentials())
    );

    int x;
    char s = 'N';
    while(s != 'y'){
        std::cout<<"0. Square random number\n1. Send random numbers\n";
        std::cin>>x;

        if(x){
            std::cout<< "-------------Sending Random Numbers---------------\n";
            client.RandomNumbers();
        } else {
            std::cout<< "-------------Squaring Random Number---------------\n";
            client.Square();
        }
        std::cout << "Would you want to quit?(y/N)";
        std::cin >> s;

    }

    return 0;
}