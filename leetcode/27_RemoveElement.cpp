#include <vector>
using std::vector;
class Solution27 {
public:
	int removeElement(vector<int>& nums, int val) {
		int length = 0;
		for (const auto& t : nums)
		{
			if (t != val)
				nums[length++] = t;
		}
		return length;
	}
};