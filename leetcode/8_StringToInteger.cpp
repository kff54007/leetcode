#include <string>

int myAtoi(std::string str) {
	int pos = str.find_first_not_of(" ");
	int sign = 1, result = 0;
	if (str[pos] == '-' || str[pos] == '+')
	{
		sign = str[pos++] == '-' ? -1 : 1;
	}

	for (; str[pos] >= '0' && str[pos] <= '9'; pos++)
	{
		int tResult = result * 10 + str[pos] - '0';
		if (tResult / 10 != result)
			return sign > 0 ? INT_MAX : INT_MIN;
		result = tResult;
	}
	return result * sign;
}
//int main()
//{
//	int result = myAtoi("-+1 a");
//	return 0;
//}