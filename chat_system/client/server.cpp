#include "server.h"

udp_client::udp_client(const char *ip,unsigned short port):
		_ip(ip),
		_port(port)
{
}

udp_client::~udp_client()
{}

void udp_client::print_log(std::string log)
{
#ifdef _DEBUG
	std::cout<<log<<std::endl;
#endif
}

void udp_client::init(struct sockaddr_in &local)
{
	local.sin_family = AF_INET;
	local.sin_port = htons(_port);
	local.sin_addr.s_addr = inet_addr(_ip);
}

int udp_client::realiable_send(int sock, std::string msg,struct sockaddr_in *remote,socklen_t len)
{
	ssize_t ret = send_msg(sock, msg, (struct sockaddr_in *)remote, len);
	if(ret < 0)
	{
		print_log("send failed");
	}
	else
	{
		print_log("send success");
	}
}

int udp_client::send_msg(int sock, std::string msg,struct sockaddr_in *remote,socklen_t len)
{
	//std::cout<<"sock:"<<sock<<" remote_ip:"<<_ip<<" remote_port:"<<_port<<std::endl;
	int ret = sendto(sock, msg.c_str(), msg.size(), 0, (struct sockaddr*)remote,len);
	if( ret < 0)
	{
		print_log("sendto failed");
		return 0;
	}
	return ret;
}

void udp_client::realiable_recv(int sockfd, char *&buf, int size)
{
	recv_msg(sockfd, buf, size);
}

void udp_client::recv_msg(int sockfd, char *&buf, int size)
{
	struct sockaddr_in client;
	socklen_t len=0;
	
	ssize_t ret = recvfrom(sockfd, buf, size, size, (struct sockaddr*)&client, &len);
	if(ret < 0)
	{//error
		print_log("recvfrom failed");
		std::cout<<"failed"<<std::endl;
		exit(1);
	}
	else if(ret == 0)
	{//close
		print_log("sock close");
	}
	else
	{//success
		print_log("recvfrom success");
	}
}





