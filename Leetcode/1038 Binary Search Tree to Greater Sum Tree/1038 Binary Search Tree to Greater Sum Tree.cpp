#include<iostream>
#include"__Tree codes.h"

using namespace std;

class Solution {
private:
	int sum;
public:
	TreeNode* bstToGst(TreeNode* root) {
		sum = 0;
		dfs(root);
		return root;
	}
	
	void dfs(TreeNode* t) {
		if (t) {
			dfs(t->right);
			sum += t->val;
			t->val = sum;
			dfs(t->left);
		}
	}
};
int main() {
	int nums[] = { 5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1 };
	struct TreeNode* root = createTreeFromArray(nums, sizeof(nums)/sizeof(nums[0]));
	bt_print(root);
	Solution solution;
	solution.bstToGst(root);
	bt_print(root);
	getchar();
	return 0;
}