#include "udp_data.h"

udp_data::udp_data()
{}

udp_data::~udp_data()
{}

void udp_data::get_nickk_name(std::string &_name)
{
	_name = nick_name;
}

void udp_data::get_school(std::string &_school)
{
	_school = school;
}

void udp_data::get_msg(std::string &_msg)
{
	_msg = msg;
}

void udp_data::get_cmd(std::string &_cmd)
{
	_cmd = cmd;
}

void udp_data::set_nickname(std::string &_name)
{
	this->nick_name = _name;
}

void udp_data::set_school(std::string &_school)
{
	this->school = _school;
}

void udp_data::set_msg(std::string &_msg)
{
	this->msg = _msg;
}

void udp_data::set_cmd(std::string &_cmd)
{
	this->cmd = _cmd;
}

bool udp_data::val_to_str(std::string &_out_str)
{//序列化
	Json::Value _val;
	_val["nick_name"] = this->nick_name;
	_val["school"] = this->school;
	_val["msg"] = this->msg;
	_val["cmd"] = this->cmd;

	if(myjson::serialize(_val,_out_str) == 0 )
	{ return true; }
	else
	{ return false; }
}

bool udp_data::str_to_val(std::string &_in_str)
{//反序列化
	Json::Value _val;
	chat_info.deserialize(_in_str, _val);
	
	this->nick_name = _val["nick_name"].asString();	
	this->school = _val["school"].asString();
	this->msg = _val["msg"].asString();
	this->cmd = _val["cmd"].asString();
	return true;
}

#ifdef _DEBUG_
int main()
{
	return 0;
}
#endif
