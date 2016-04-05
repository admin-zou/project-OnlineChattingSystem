#include "json/json.h"
#include <string>
#include <iostream>


class myjson
{
public:
	myjson();
	~myjson();
	static int serialize(Json::Value &_in_val, std::string &_str_out);
	static int deserialize(std::string &_str_out, Json::Value &_in_val);
};



//int main()
//{
//	string test="{\"id\":1,\"name\":\"jack\"}";
//	Json::Reader reader;
//	Json::Value value;
//
//	if(reader.parse(test,value))
//	{
//		if(!value["id"].isNull())
//		{
//			cout<<value["id"].asInt()<<endl;
//			cout<<value["name"].asString()<<endl;
//		}
//	}
//
//	return 0;
//}
