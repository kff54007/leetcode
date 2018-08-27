#include <vector>
#include <algorithm>
using std::vector;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	std::sort(nums.begin(), nums.end());
	for (int i = 0; i < (int)nums.size() - 3; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < nums.size() - 2; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;
			for (int k = j + 1, l = nums.size() - 1; k < l;)
			{
				if (k > j + 1 && nums[k] == nums[k - 1])
				{
					k++;
					continue;
				}
				else if (l < nums.size() - 1 && nums[l] == nums[l + 1])
				{
					l--;
					continue;
				}
				auto sum = nums[i] + nums[j] + nums[k] + nums[l];
				if (sum < target)
					k++;
				else if (sum > target)
					l--;
				else {
					result.push_back({ nums[i], nums[j], nums[k], nums[l] });
				}
			}
		}
	}
	return result;
}

int main()
{
	std::vector<int> y{ -2,-1,0,0,1,2 };
	auto tt = fourSum(y,0);
	return 0;
}