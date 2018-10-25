#include <string>
using std::string;
class Solution28 {
public:
	//Brute-Force
	size_t q;
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		if (needle.size() > haystack.size())
			return -1;
		for (int i = 0; i < haystack.size() - needle.size() + 1; i++)
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
int main()
{
	Solution28 a;
	a.strStr("abb", "abaaa");
	return 0;
}