#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
class Solution39
{
public:
	void find(vector<vector<int>>& ret, vector<int>& one, vector<int>& candidates, int target, int begin)
	{
		if (target == 0)
		{
			ret.push_back(one);
			return;
		}
		for (int i = begin; i < candidates.size() && candidates[i] <= target; i++) 
		{
			one.push_back(candidates[i]);
			find(ret, one, candidates, target - candidates[i], i);
			one.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>&& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<int> one;
		vector<vector<int>> ret;
		find(ret, one, candidates, target, 0);
		return ret;
	}
};

int main()
{
	Solution39 a;
	auto t = a.combinationSum({ 2,3,5 }, 8);
	return 0;
}