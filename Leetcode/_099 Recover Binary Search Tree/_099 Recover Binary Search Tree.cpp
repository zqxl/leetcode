#include"__Tree codes.h"
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
	vector<int> nums;
public:
	void recoverTree(TreeNode* root) {
		dfs(root);
		sort(nums.begin(), nums.end());
		dfsset(root);
	}
	void dfs(TreeNode* t) {
		if (t) {
			dfs(t->left);
			nums.push_back(t->val);
			dfs(t->right);
		}
	}
	void dfsset(TreeNode* t) {
		if (t) {
			dfsset(t->right);
			t->val = nums.back();
			nums.pop_back();
			dfsset(t->left);
		}
	}
};