#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	while (root) {
		if (p->val > root->val) {
			if (q->val > root->val)
				root = root->right;
			else if (q->val <= root->val)
				return root;
		}
		else if (p->val < root->val) {
			if (q->val < root->val)
				root = root->left;
			else if (q->val >= root->val)
				return root;
		}
		else
			return root;
	}
	return NULL;
}
