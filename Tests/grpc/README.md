# Instructions to run this **gRPC** test:

## 1. Changes in the Makefile:
Change the all the occorunces of directory paths _(/home/darshit/.local/lib/pkgconfig_ or _/home/darshit/.local/bin/protoc)_ according to the paths of the directory of your installation, in the Makefile. 
```c
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
```

```
PROTOC = /home/darshit/.local/bin/protoc
```

## 2. Making
Run the make command:
`$ make`
**Note: If there is any difficulty in making the project then you need to carefully check the location of packages**

## 3. Running the server and client.
1. To run the server
`$ ./grpc_server`
2. To run the client you need to open a different terminal and run 
`$ ./grpc_client`



