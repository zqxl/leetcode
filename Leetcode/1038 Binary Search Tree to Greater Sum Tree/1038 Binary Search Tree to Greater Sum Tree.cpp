#include<iostream>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 由二维数组生成二叉树
struct TreeNode *createTreeFromArray(int *nums, int numsSize) {
	const int numMeansNull = 0;
	struct TreeNode *nodes = (struct TreeNode*)calloc(numsSize, sizeof(struct TreeNode));
	for (int i = 0; i < numsSize; i++) {
		nodes[i].val = nums[i];
		int child = i * 2 + 1;
		nodes[i].left = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
		child = i * 2 + 2;
		nodes[i].right = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
	}
	return &nodes[0];
}


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
	int nums[] = { 5,4,8,11,0,13,4,7,2,0,0,0,0,5,1 };
	struct TreeNode* root = createTreeFromArray(nums, 15);
	Solution solution;
	solution.bstToGst(root);
	return 0;
}