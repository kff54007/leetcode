#include <vector>
#include <algorithm>
int threeSumClosest(std::vector<int>&& nums, int target) {
	std::sort(nums.begin(), nums.end());
	int result = INT_MAX;
	for (int i = 0; i < (int)nums.size() - 2; i++)
	{
		if (i > 0 && nums[i - 1] == nums[i])
			continue;
		for (int j = i + 1, k = nums.size() - 1; j < k;)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
			{
				j++;
				continue;
			}
			if (k < nums.size() - 1 && nums[k] == nums[k + 1])
			{
				k--;
				continue;
			}
			if (abs(target - result) > abs(target - (nums[i] + nums[j] + nums[k])))
				result = nums[i] + nums[j] + nums[k];
			if (nums[i] + nums[j] + nums[k] == target)
				return target;
			else if (nums[i] + nums[j] + nums[k] > target)
				k--;
			else
				j++;
			
		}
	}
	return result;
}
//int main()
//{
//	auto tt = threeSumClosest({ -10,0,-2,3,-8,1,-10,8,-8,6,-7,0,-7,2,2,-5,-8,1,-4,6 },18);
//	return 0;
//}