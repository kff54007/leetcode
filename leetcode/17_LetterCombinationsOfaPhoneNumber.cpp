#include <string>
#include <vector>
#include <array>
std::vector<std::string> letterCombinations(std::string digits) {
	std::array<std::string, 10> dic{ "","","abc","def","ght","jkl","mno","pqrs","tuv","wxyz" };
	std::vector<std::string> result{ "" };
	for (const auto& digit : digits)
	{
		std::vector<std::string> tResult;
		for (int j = 0; j < result.size(); j++)
			for (int i = 0; i < dic[digit - '0'].size(); i++)
				tResult.push_back(result[j] + std::string{ dic[digit - '0'][i] });
		result.swap(tResult);
	}
	return result;
}

int main()
{
	letterCombinations("23");
		return 0;
}