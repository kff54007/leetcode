#include <vector>
#include <iterator>
class Solution31 {
public:
	void nextPermutation(std::vector<int>& nums) {
		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (nums[i - 1] < nums[i])
			{
				for (int j = nums.size() - 1; j >= i; j--)
				{
					if (nums[j] > nums[i - 1])
					{
						std::swap(nums[j], nums[i - 1]);
						std::reverse(nums.begin() + i, nums.end());
						return;
					}
				}
			}
		}
		std::reverse(nums.begin(), nums.end());
	}
};