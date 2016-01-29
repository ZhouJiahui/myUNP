#pragma once
#include <string>
class Noncopyable
{
protected:
	Noncopyable(){}
private:
	Noncopyable(const Noncopyable&)=delete;
	void operator=(const Noncopyable&)=delete;		
};

class Copyable
{
};

class StringArg:Copyable
{
public:
	StringArg(const char *str):str_(str)
	{}
	StringArg(const std::string &str):str_(str.c_str())
	{}
	const char* c_str() const
	{
		return str_;
	}
private:
	const char *str_;
};

template<typename To,typename From>
inline To implicit_cast(const From &f)
{
	return f;
}

