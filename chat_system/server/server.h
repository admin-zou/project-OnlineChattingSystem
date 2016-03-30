#pragma once

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string>
#include <map>
#include "data_pool.h"
#include "udp_data.h"

class udp_server
{
public:
	udp_server( unsigned short port = 8080 );
	void init_server();
	int realiable_send(std::string msg,struct sockaddr_in &remote);
	int realiable_recv();
	void regestor(std::string ip, struct sockaddr_in user);
	void broadcast();
	void print_log(std::string msg);
	~udp_server();

private:
	int send_msg(std::string msg,struct sockaddr_in &remote);
	int recv_msg();

private:
	int sock;
	unsigned short _port;
	std::map<std::string,struct sockaddr_in> _online_user;
	data_pool _pool;
};

