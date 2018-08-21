#include <vector>
#include <algorithm>
int maxArea(std::vector<int>& height) {
	int i = 0, j = height.size() - 1;
	int result = 0;
	while (i != j)
	{
		result = std::max(result, (j - i) * std::min(height[i], height[j]));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return result;
}