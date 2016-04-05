#include "myjson.h"

myjson::myjson()
{}

myjson::~myjson()
{}

int myjson::serialize(Json::Value &_in_val, std::string &_str_out)
{
#ifdef _STYTLE
		Json::StyledWriter _writer;
#else
		Json::FastWriter _writer;
#endif
		_str_out = _writer.write(_in_val);

		return 0;
}

int myjson::deserialize(std::string &_str_out, Json::Value &_in_val)
{
		Json::Reader _reader;
		if( _reader.parse(_str_out,_in_val, false) )
		{//success
			return 0;
		}
		else
		{//failed
			return 1;
		}
}

#ifdef _DEBUG_
int main()
{
	std::string _str_out;
	Json::Value _val;
	_val["name"]="fly pig";
	_val["school"] = "XATU";
	_val["msg"] = "hello";
	myjson::serialize(_val, _str_out);
	std::cout<<_str_out<<std::endl;
	
	Json::Value _out_val;
	myjson::deserialize(_str_out,_out_val);
	std::cout<<_out_val["name"];
	std::cout<<_out_val["school"];
	std::cout<<_out_val["msg"];
	return 0;
}
#endif
