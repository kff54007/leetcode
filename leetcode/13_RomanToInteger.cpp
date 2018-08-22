#include <unordered_map>
#include <string>
int romanToInt(std::string s) {
	std::unordered_map<char, int> tMap{ 
		{ 'I' , 1 },
		{ 'V' , 5 },
		{ 'X' , 10 },
		{ 'L' , 50 },
		{ 'C' , 100 },
		{ 'D' , 500 },
		{ 'M' , 1000 } };
	int result = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (tMap[s[i]] < tMap[s[i + 1]])
		{
			result += tMap[s[i + 1]] - tMap[s[i]];
			i++;
		}
		else
			result += tMap[s[i]];
	}
	return result;
}