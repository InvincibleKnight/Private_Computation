HOST_SYSTEM = $(shell uname | cut -f 1 -d_)
SYSTEM ?= $(HOST_SYSTEM)
CXX = g++
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11
ifeq ($(SYSTEM),Darwin)
LDFLAGS += -L/home/darshit/.local/lib/pkgconfig `pkg-config --libs protobuf grpc++`\
           -isystem /home/darshit/.local/include\
					 -pthread\
           -lgrpc++_reflection\
           -ldl
else
LDFLAGS += -L/home/darshit/.local/lib/pkgconfig `pkg-config --libs protobuf grpc++`\
            -isystem /home/darshit/.local/include\
           -pthread\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
endif
PROTOC = /home/darshit/.local/bin/protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

PROTOS_PATH = .

vpath %.proto $(PROTOS_PATH)

all: task.pb.cc task.grpc.pb.cc task.pb.o task.grpc.pb.o grpc_client grpc_server

grpc_client: task.pb.o task.grpc.pb.o grpc_client.o
	$(CXX) $^ $(LDFLAGS) -o $@

grpc_server: task.pb.o task.grpc.pb.o grpc_server.o
	$(CXX) $^ $(LDFLAGS) -o $@

%.grpc.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<

%.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=. $<

clean:
	rm -f *.o *.pb.cc *.pb.h grpc_client grpc_server

