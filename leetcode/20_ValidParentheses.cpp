#include <string>
#include <stack>
bool isValid(std::string s) {
	std::stack<char> tmp;
	for (const auto& letter : s)
	{
		switch (letter)
		{
		case '(':
		case '{':
		case '[':
			tmp.push(letter);
			continue;
			break;
		}
		if (tmp.empty())
			return false;

		switch (letter)
		{
		case ')':
			if (tmp.top() == '(')
				tmp.pop();
			else
				return false;
			break;
		case '}':
			if (tmp.top() == '{')
				tmp.pop();
			else
				return false;
			break;
		case ']':
			if (tmp.top() == '[')
				tmp.pop();
			else
				return false;
			break;
		}
	}
	return tmp.empty();
}
//int main()
//{
//	isValid("]");
//	return 0;
//}