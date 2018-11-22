#include <string>
class Solution38 {
public:
	std::string countAndSay(int n) {
		auto begin = std::string{ "1" };
		for (int i = 0; i < n - 1; i++)
		{
			int count = 1;
			std::string now;
			for (int j = 0; j < begin.size(); j++)
			{
				if (j + 1 != begin.size() && begin[j] == begin[j + 1])
					count++;
				else {
					now += std::to_string(count * 10 + begin[j] - '0');
					count = 1;
				}
			}
			begin = now;
		}
		return begin;
	}
};
