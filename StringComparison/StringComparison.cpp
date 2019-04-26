#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
bool caseInsensitiveStringsAreEqual(const string& str1, const string& str2)
{
	if (str1.size() != str2.size())
		return false;

	for (int i = 0; i < str1.size(); i++)
	{
		if (toupper(str1[i]) != toupper(str2[i]))
			return false;
	}
	return true;
}
int main()
{
	string str1 = "ABCD";
	string str2 = "abce";
	bool result = caseInsensitiveStringsAreEqual(str1, str2);
    std::cout <<  boolalpha << result; 
}
