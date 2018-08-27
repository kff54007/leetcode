#include <vector>
#include<algorithm>
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
	std::vector<std::vector<int>> result;
	std::sort(nums.begin(), nums.end());
	size_t;
	auto tt = nums.size();
	for (int i = 0; i < nums.size() - 2; i++)
	{
		if (i > 0 && nums[i - 1] == nums[i])
			continue;
		for (int j = i + 1, k = nums.size() - 1; j < k;)
		{
			if (j > i + 1 && nums[j - 1] == nums[j])
			{
				j++;
				continue;
			}
			if (k < nums.size() - 1 && nums[k] == nums[k + 1])
			{
				k--;
				continue;
			}
			if (nums[i] + nums[j] + nums[k] == 0)
			{
				result.push_back({ nums[i] , nums[j] , nums[k] });
				j++;
				k--;
			}
			else if (nums[i] + nums[j] + nums[k] < 0)
				j++;
			else
				k--;
		}
	}
	return result;
}
//int main()
//{
//	std::vector<int> tmp{};
//	auto t = threeSum(tmp);
//	return 0;
//}