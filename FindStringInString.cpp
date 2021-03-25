#include <iostream>
#include <string>

using namespace std;

bool FindStringInString(std::string& s, std::string& sfind)
{
	for (int i = 0; i < s.size(); i++)								
	{
		int cnt = 1;												
		if (s[i] == sfind[0])									
			for (int j = 1, si = i+1; j < sfind.size(); j++, si++)	
			{
				if (sfind[j] == s[si]) cnt++;						
				else break;
			}
		if (cnt == sfind.size())									
		{
			return true;
		}
	}
	return false;
}

int main()
{
	string s1 = "Hello World!"; // where to look for

	string s2 = "elo"; // what to look for

	cout << FindStringInString(s1, s2);
	return 0;
}