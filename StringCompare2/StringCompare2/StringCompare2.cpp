#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
//#include <boost/algorithm/string.hpp>


using namespace std;

bool stringIsMatch(const string &input, const string &pattern)
{
	pair<bool, char> repetitionCheckIndex(false, ' ');

	
	for (int  inputIter = 0, i = 0 ; i < pattern.size(); i++)
	{
		if (repetitionCheckIndex.first == true)
			if (repetitionCheckIndex.second == toupper(input[inputIter]))
			{
				inputIter += 1;
				if (i > 0)
					i -= 1;
				continue;
			}
			else if (repetitionCheckIndex.second == '.')
			{
				inputIter += 1;
				continue;
			}
			else
			{
				repetitionCheckIndex.first = false;
				repetitionCheckIndex.second = ' ';	
				continue;
			}
		
		if (i <= pattern.size() - 1 && repetitionCheckIndex.first == false)
			if (pattern[i + 1] == '*')
			{
				repetitionCheckIndex.first = true;
				repetitionCheckIndex.second = toupper(pattern[i]);
				continue;
			}

		if (pattern[i] == '.')
		{
			inputIter += 1;
			continue;
		}
		else if (toupper(input[inputIter]) == toupper(pattern[i]))
		{
			inputIter += 1;
			continue;
		}

		return false;		
	}
	return true;
}

int main()
{
	bool isMatch = stringIsMatch("aaabbcczxeehighf", "a*b*cc..ee.*");
	cout << boolalpha << isMatch;
}
