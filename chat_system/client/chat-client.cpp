#include "server.h"
#include <stdio.h>

int main()
{
	udp_client client;
	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	struct sockaddr_in remote;
	client.init(remote);
	socklen_t len = sizeof(remote);
	
	char buf[1024];
	char *recv_buf=new char[1024];

	while(1)
	{
		memset(buf, '\0', sizeof(buf));
		std::cout<<"please input:";
		fflush(stdout);	
		std::cin>>buf;
		client.realiable_send(sock, buf, &remote, len);
		
		memset(recv_buf, '\0', sizeof(char)*1024);
		client.realiable_recv(sock, recv_buf, sizeof(char)*1024);
		std::cout<<recv_buf<<std::endl;
	}

	return 0;
}
