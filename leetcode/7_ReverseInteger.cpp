#include <iostream>
#include <string>
#include <algorithm>

int reverseInt32(int x) {
	int result = 0;
	while (x != 0)
	{
		int pop = x % 10;
		if (result > INT_MAX / 10 || result < INT_MIN / 10 || result * 10 == INT_MAX && pop > 7 || result * 10 == INT_MIN && pop < -8)
			return 0;
		x /= 10;
		result = result * 10 + pop;
	}
	return result;
}

static const auto io_sync_off = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();

int main()
{
	std::cout << reverseInt32(1000000009);
	system("pause");
	return 0;
}