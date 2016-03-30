#include "server.h"
#include "udp_data.h"
#include <pthread.h>


void* recvmsg(void *arg)
{
	udp_server *server = (udp_server *)arg;
	while(1)
	{
		server->realiable_recv();
		sleep(2);
	}
}

void* sendmsg(void *arg)
{
	udp_server *server = (udp_server *)arg;
	while(1)
	{
		server->broadcast();
		sleep(2);
	}
}

int main(int argc, char *argv[])
{
	if( argc != 2)
	{
		printf("Usage:%s [port]\n",argv[0]);
		return 1;
	}

	udp_server server;
	server.init_server();
	pthread_t tid1, tid2;
	pthread_create(&tid1, 0, recvmsg,(void*)&server);
	pthread_create(&tid2, 0, sendmsg,(void*)&server);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	return 0;
}
