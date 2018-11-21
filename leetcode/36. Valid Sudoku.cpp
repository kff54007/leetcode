#include<vector>
using std::vector;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<short> row(9, 0);
		vector<short> column(9, 0);
		vector<short> block(9, 0);
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board.size(); j++)
			{
				if (board[i][j] == '.')
					continue;
				auto target = 1 << (board[i][j] - '0');
				if (target & row[i] || target & column[j] || target & block[i / 3 * 3 + j / 3])
					return false;
				row[i] |= target;
				column[j] |= target;
				block[i / 3 * 3 + j / 3] |= target;
			}
		return true;
	}
};