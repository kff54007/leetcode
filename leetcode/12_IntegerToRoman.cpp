#include <string>
#include <vector>
std::string intToRoman(int num) {
	std::vector<std::string> ones{ "","I","II","III","IV","V","VI","VII","VIII","IX" };
	std::vector<std::string> tens{ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
	std::vector<std::string> hundreds{ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
	std::vector<std::string> thousands{ "","M","MM","MMM" };
	return thousands[num / 1000] + hundreds[num / 100 % 10] + tens[num / 10 % 10] + ones[num % 10];
}