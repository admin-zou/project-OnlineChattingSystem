#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

class udp_client
{
public:
	udp_client(const char *ip="127.0.0.1",unsigned short port=8080);
	~udp_client();
	void init(struct sockaddr_in &local);
	int realiable_send(int sock, std::string msg,struct sockaddr_in *remote,socklen_t len);
	void realiable_recv(int sockfd, char *&buf, int size);
	void print_log(std::string log);
private:
	int send_msg(int sock,std::string msg,struct sockaddr_in *remote, socklen_t len);
	void recv_msg(int sock, char *&buf, int size);

private:
	const char *_ip;
	unsigned short _port;
};
