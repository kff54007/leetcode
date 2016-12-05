#include <iostream>
#include <map>
#include <unordered_map>//ÎÞÐòmap c++11
using namespace std;
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		map<char, int> tMap;
		for (int i = 0; i < magazine.size(); i++)
		{
			if (tMap.find(magazine[i]) == tMap.end())
				tMap[magazine[i]] = 1;
			else
				tMap[magazine[i]]++;
		}
		for (int i = 0; i < ransomNote.size(); i++)
		{
			auto itr = tMap.find(ransomNote[i]);
			if (itr == tMap.end())
				return false;
			else if (itr->second <= 0)
				return false;
			else
				itr->second--;
		}
		return true;
	}
	bool canConstructBetter(string ransomNote, string magazine) {
		for (int i = 0; i<ransomNote.length(); i++){
			if (magazine.find(ransomNote[i]) != string::npos)
				magazine[magazine.find(ransomNote[i])] = '\0';
			else
				return false;
		}
		return true;
	}
};


