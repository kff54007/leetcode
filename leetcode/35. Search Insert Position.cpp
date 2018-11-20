#include <vector>
using std::vector;
class Solution35 {
public:
	int searchInsert(vector<int>& nums, int target) {
		int low = 0, high = nums.size();
		while (low < high)
		{
			auto mid = (high + low) / 2;
			if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid;
		}
		return low;
	}

};
