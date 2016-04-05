#myjson:myjson.cpp
udp_data:udp_data.cpp myjson.cpp
	g++ -o $@ $^ -I ./ -I ../lib/include/  -L ../lib/libs -ljson -D_STYTLE

.PHONY:clean
clean:
	rm udp_data
	#rm myjson

