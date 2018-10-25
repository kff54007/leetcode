#include <string>
using std::string;
class Solution28 {
public:
	//Brute-Force
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		for (int i = 0; i < haystack.size(); i++)
		{
			int j = 0;
			for (; j < needle.size(); j++)
			{
				if (haystack[j + i] != needle[j])
					break;
			}
			if (j == needle.size())
				return i;
		}
		return -1;
	}
	//KMP
	//...
};