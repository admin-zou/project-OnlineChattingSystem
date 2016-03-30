chat-server:chat-server.cpp server.cpp ../data_pool/data_pool.cpp
	g++ -o $@ $^ -I ../data_pool -I ../comm/ -L ../lib/libs -ljson -lpthread

.PHONY:clean
clean:
	rm chat-server
