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
	std::string source_weather_string;  //�洢��ȡ��������Դ��



};
//��������
std::string UnicodeToUTF8(const std::wstring& str);
std::string UnicodeToANSI(const std::wstring& str);
std::wstring ANSIToUnicode(const std::string& str);
std::wstring UTF8ToUnicode(const std::string& str);

