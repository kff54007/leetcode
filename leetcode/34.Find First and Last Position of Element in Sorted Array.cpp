#include <vector>
using std::vector;
class Solution34 {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		vector<int> ret{ -1,-1 };
		if (nums.empty())
			return ret;
		while (low < high)
		{
			auto mid = low + ((high - low) >> 1);
			if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid;
		}
		if (nums[high] != target)
			return ret;
		ret[0] = high;
		high = nums.size() - 1;
		while (low < high)
		{
			auto mid = low + ((high - low) >> 1) + 1;
			if (nums[mid] > target)
				high = mid - 1;
			else
				low = mid;
		}
		if (nums[high] == target)
			ret[1] = high;
		return ret;
	}
};