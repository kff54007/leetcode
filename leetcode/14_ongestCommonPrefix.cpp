#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
	std::string result;
	if (strs.empty())
		return result;
	for (int i = 0; i < strs[0].size(); i++)
	{
		for (int j = 0; j < strs.size(); j++)
		{
			if (i > strs[j].size() - 1 || j > 0 && strs[j][i] != strs[j - 1][i] )
				return result;
		}
		result += strs[0][i];
	}
	return result;
}

//int main()
//{
//	std::vector<std::string> tmp{ "flower", "flow", "flight" };
//	longestCommonPrefix(tmp);
//	return 0;
//}