#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// µÝ¹é
class Solution2 {
public:
	vector<vector<int>> data;
	int sum;
	int minv = 0x7fffffff;
	int minimumTotal(vector<vector<int>>& triangle) {
		data = triangle;
		sum = data[0][0];
		dfs(0, 0);
		return minv;
	}

	void dfs(int i, int j) {
		
		if (i == data.size() - 1) {
			minv = minv < sum ? minv : sum;
			return;
		}
		sum += data[i + 1][j];
		dfs(i + 1, j);
		sum -= data[i + 1][j];

		sum += data[i + 1][j + 1];
		dfs(i + 1, j + 1);
		sum -= data[i + 1][j + 1];
	}
};

// ¶¯Ì¬¹æ»®
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> dp(triangle);
		int row = triangle.size();
		for (int i = row - 2; i >= 0; i--) {
			int col = triangle[i].size();
			for (int j = 0; j<col; j++) {
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return dp[0][0];
	}
};

void main() {
	vector<vector<int>> data(4);
	for (int i = 0; i < 4; i++) {
		data[i].resize(i + 1);
	}
	data[0] = { 2 };
	data[1] = { 3, 4 };
	data[2] = { 6, 5, 7 };
	data[3] = { 4, 1, 8, 3 };

	Solution2 s;
	s.minimumTotal(data);
	getchar();
}
