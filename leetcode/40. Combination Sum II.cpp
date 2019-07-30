#include <vector>
#include <algorithm>

using std::vector;

class Solution40
{
public:
	void find(vector<int>& one, vector<vector<int>>& ret, vector<int>& candidates, int target,int level) {
		if (target == 0) {
			ret.push_back(one);
			return;
		}
		for (int i = level; i < candidates.size(); i++) {
			if (target > candidates[i])
				continue;
			if (i && candidates[i] == candidates[i - 1] && i > level)
				continue;
			one.push_back(candidates[i]);
			find(one, ret, candidates, target - candidates[i], i + 1);
			one.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>&& candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		vector<int> one;
		vector<vector<int>> ret;
		find(one, ret, candidates, target, 0);
		return ret;
	}
private:

};

//int main() {
//	Solution40 a;
//	auto ret = a.combinationSum2({ 10,1,2,7,6,1,5 }, 8);
//	return 0;
//}