#include "server.h"

udp_server::udp_server( unsigned short port):
		_port(port)
{
		sock = -1;
}

udp_server::~udp_server()
{}

void udp_server::print_log(std::string log)
{
#ifdef _DEBUG
	std::cout<<log<<std::endl;
#endif
}

void udp_server::init_server()
{
	sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0)
   	{
		perror("socket");
		exit(1);
	}	
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(_port);
	local.sin_addr.s_addr = htonl(INADDR_ANY); //自动绑定ip
	socklen_t len = sizeof(local);

	if( bind(sock, (struct sockaddr*)&local, len) < 0 )
	{
		perror("bind");
		exit(2);
	}
	print_log("bind suceess");
	return ;
}

void udp_server::regestor(std::string ip, struct sockaddr_in user)
{
	
	std::map<std::string,struct sockaddr_in>::iterator it = _online_user.begin();

	for(;it != _online_user.end(); ++it)
	{
		if(it->first == ip)
		{
			break;
		}
	}

	if(it == _online_user.end())
	{
		_online_user.insert(std::pair<std::string , struct sockaddr_in>(ip,user));
		print_log("reagester success");
	}
}

void udp_server::broadcast()
{
	std::string msg;
	_pool.get_data(msg);
	//std::cout<<"get_data->"<<msg<<std::endl;
	std::map<std::string,struct sockaddr_in>::iterator it = _online_user.begin();
	for(;it != _online_user.end(); ++it)
	{
		//std::cout<<"send msg->"<<msg.c_str()<<" port->"<<it->second.sin_port<<std::endl;
		realiable_send(msg.c_str(), it->second);
	}
}

int udp_server::realiable_send(std::string msg,struct sockaddr_in &remote)
{
	return send_msg(msg, remote);
}

int udp_server::send_msg(std::string msg,struct sockaddr_in &remote)
{
	socklen_t len = sizeof(remote);
	ssize_t ret = sendto(sock, msg.c_str(), msg.size(), 0, (struct sockaddr*)&remote, len);
	if( ret < 0)
	{
		print_log("sendto failed");
		std::cout<<"send failed"<<std::endl;
		return 0;
	}

	print_log("send success");
	return ret;
}


int udp_server::realiable_recv()
{
	int ret = recv_msg();
	return ret;
}

int udp_server::recv_msg()
{
	char buf[1024];
	memset(buf, '\0', sizeof(buf));
	struct sockaddr_in client;
	socklen_t len = sizeof(client);
	
	ssize_t ret = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&client, &len); //len参数指定缓冲区的长度，若想获取远端信息，且不可传递0进去
	if(ret < 0)
	{//error
		print_log("recvfrom failed");
		return -1;
	}
	else if(ret == 0)
	{//close
		print_log("sock close");
		return 0;
	}
	else
	{//success
			buf[ret] = '\0';
			fflush(stdout);
			std::string ip = inet_ntoa(client.sin_addr);
			std::cout<<ip<<" say: "<<buf<<std::endl;
			//std::cout<<ip<<std::endl;
			//std::cout<<client.sin_port<<std::endl;
			regestor(ip,client);
			_pool.put_data(buf);
	}

	return ret;
}



