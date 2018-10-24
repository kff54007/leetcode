#include <vector>
using std::vector;
class Solution26 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int length = 1;
		for (const auto& t:nums)
		{
			if (nums[length - 1] != t)
				nums[length++] = t;
		}
		return length;
	}
};