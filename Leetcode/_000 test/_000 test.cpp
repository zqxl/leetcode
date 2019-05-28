#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<vector<int>> dp(triangle);
		int row = triangle.size();
		for (int i = 0; i<triangle[row - 1].size(); i++) {
			dp[row - 1][i] = triangle[row - 1][i];
		}
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

	Solution s;
	s.minimumTotal(data);
	getchar();
}
