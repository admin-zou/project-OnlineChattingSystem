#pragma once
#include <iostream>
#include <string>
#include "myjson.h"

class udp_data
{
public:
	udp_data();
	bool val_to_str(std::string &_out_str);
	bool str_to_val(std::string &_in_str);
	~udp_data();

protected:
	void get_nickk_name(std::string &_name);
	void get_school(std::string &_school);
	void get_msg(std::string &__msg);
	void get_cmd(std::string &_cmd);
	void set_nickname(std::string &_name);
	void set_school(std::string &_school);
	void set_msg(std::string &_msg);
	void set_cmd(std::string &_cmd);

private:
	myjson chat_info;	
	std::string nick_name;
	std::string school;
	std::string msg;
	std::string cmd;
};
