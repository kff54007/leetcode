#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class trace {
	int sum_ = 0;
	vector<int> sk_;
public:
	void push(int s) {
		sum_ += s;
		sk_.emplace_back(s);
	}
	void pop() {
		sum_ -=  sk_.back();
		sk_.pop_back();
	}
	int sum() {
		return sum_;
	}
	vector<int> one() {
		return sk_;
	}
};
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

	vector<vector<int>> combinationSum2(vector<int>&& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> ret;
		trace tr;
		vector<int> level;
		for (tr.push(0), level.emplace_back(-1); !level.empty(); level.pop_back(), tr.pop()) {
			if (level.back() + 1 >= candidates.size()) {
				continue;
			}
			level.back()++;
			tr.pop();
			tr.push(candidates[level.back()]);
			while (true) {
				if (tr.sum() < target) {
					level.emplace_back(level.back());
					tr.push(candidates[level.back()]);
					continue;
				}
				if (tr.sum() == target) {
					ret.emplace_back(tr.one());
				}
				break;
			}
		}
		return ret;
	}
};



int main()
{
	Solution39 a;
	auto t = a.combinationSum2({ 2,3,5 }, 8);
	return 0;
}