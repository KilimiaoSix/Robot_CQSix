#pragma once
#include <string>
#include <Windows.h>

class Weather
{
public:
	Weather();
	~Weather();
protected:

private:
	std::string source_weather_string;  //存储获取到天气的源码



};
//函数声明
std::string UnicodeToUTF8(const std::wstring& str);
std::string UnicodeToANSI(const std::wstring& str);
std::wstring ANSIToUnicode(const std::string& str);
std::wstring UTF8ToUnicode(const std::string& str);

