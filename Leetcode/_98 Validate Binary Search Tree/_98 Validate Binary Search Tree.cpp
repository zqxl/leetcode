#include"__Tree codes.h"

class Solution {
private:
	int lastVal;
	bool first;
	bool res;
public:
	bool isValidBST(TreeNode* root) {
		res = true;
		first = true;
		dfs(root);
		return res;

	}
	void dfs(TreeNode* t) {
		if (!res || !t)
			return;
		dfs(t->left);

		if (first) {
			first = false;
		}
		else{
			if (t->val <= lastVal)
				res = false;
		}
		lastVal = t->val;

		dfs(t->right);
	}
};

int main() {
	int nums[] = {5,1,4,-1,-1,3,6};
	struct TreeNode *root = createTreeFromArray(nums, sizeof(nums)/sizeof(nums[0]));
	bt_print(root);
	Solution s;
	s.isValidBST(root);
	return 0;
}