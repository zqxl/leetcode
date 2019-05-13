#include<iostream>
#include<vector>

#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))

using namespace std;

void print2Dvector(vector<vector<char>> x) {
	printf("\n");
	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x[i].size(); j++) {
			if (x[i][j] < 10) {
				printf("%d ", x[i][j]);
			}
			else {
				printf("%c ", x[i][j]);
			}
			
		}
		printf("\n");
	}
}

class Solution {
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		if (board[click[0]][click[1]] == 'M') {
			board[click[0]][click[1]] = 'X';
			return board;
		}

		// 初始化成员变量
		original_map.assign(board.begin(), board.end());
		vector<char> t(board[0].size(), 0);
		for (int i = 0; i < board.size(); i++) {
			status_map.push_back(t);
		}
		updatestatus_map();
		// 打印
		//print2Dvector(status_map);

		if (status_map[click[0]][click[1]] > 0 ) {
			original_map[click[0]][click[1]] = status_map[click[0]][click[1]] + 0x30;
			return original_map;
		}

		dfs(click[0], click[1]);

		return original_map;
	}
private:
	vector<vector<char>> original_map;
	vector<vector<char>> status_map;

	void updatestatus_map() {
		for (int i = 0; i < original_map.size(); i++) {
			for (int j = 0; j < original_map[i].size(); j++) {
				if (original_map[i][j] == 'M') {
					setNumsAroundMine(i, j);
				}
			}
		}
	}
	void setNumsAroundMine(int x, int y) {
		for (int i = max(0, x - 1); i < min(status_map.size(), x + 2); i++) {
			for (int j = max(0, y - 1); j < min(status_map[i].size(), y + 2); j++) {
				status_map[i][j]++;
			}
		}
		status_map[x][y] = -9;
	}

	void dfs(int x, int y) {
		if (status_map[x][y] > 0) {
			original_map[x][y] = status_map[x][y] + 0x30;
			return;
		}
		else if (status_map[x][y] < 0) {
			return;
		}

		original_map[x][y] = 'B';
		// 打印
		//print2Dvector(original_map);

		for (int i = max(0, x - 1); i < min(status_map.size(), x + 2); i++) {
			for (int j = max(0, y - 1); j < min(status_map[i].size(), y + 2); j++) {
				if ((x == i && y == j) || original_map[i][j]!='E')
					continue;
				dfs(i,j);
			}
		}
	}
};

int main() {
	vector<vector<char>> original_map;
	vector<char> t;

	char mapchar[][5] = { 
		{ 'E', 'E', 'E', 'E', 'E' },
		{ 'E', 'E', 'M', 'M', 'E' },
		{ 'E', 'E', 'E', 'E', 'E' },
		{ 'E', 'E', 'E', 'E', 'E' } };
	for (int i = 0; i < 4; i++) {
		original_map.push_back(t);
		for (int j = 0; j < 5; j++) {
			original_map[i].push_back(mapchar[i][j]);
		}
	}
	print2Dvector(original_map);
	
	vector<int> xy({0,0});
	
	Solution s;
	s.updateBoard(original_map, xy);

	return 0;
}
