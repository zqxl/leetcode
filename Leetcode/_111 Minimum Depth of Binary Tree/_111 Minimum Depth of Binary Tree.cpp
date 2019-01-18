#include<stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left = NULL;
	struct TreeNode *right = NULL;
};

//// 迭代法 4ms
//int max(int x, int y) { return x > y ? x : y; }
//int maxDepth1(struct TreeNode* root) {
//	if (root == NULL) return 0;
//	else if (root->left == NULL & root->right == NULL) return 1;
//	else if (root->left && root->right) return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
//	else if (root->left == NULL) return maxDepth(root->right) + 1;
//	else if (root->right == NULL) return maxDepth(root->left) + 1;
//	return 0;
//}

// ************************************      层次遍历 4ms     **************************************
int minDepth(struct TreeNode* root) {
	// 定义最大深度
	int depth = 0;
	// 节点地址组成的数组
	struct TreeNode *que[4096];
	// 队列的起始和终止
	int start = 0, end = 0;
	// 入栈
	if (root)
		que[end++] = root;
	else
		return 0;

	while (end - start >0) {
		depth++;
		// 记录本层最左最右的节点位置
		int left_nest = start, right_nest = end;
		for (int i = left_nest; i < right_nest; i++) {
			if (que[i]->left ==NULL && que[i]->right == NULL)				
				return depth;

			if (que[i]->left)
				que[end++] = que[i]->left;
			if (que[i]->right) 		
				que[end++] = que[i]->right;
		}
		start = right_nest;
	}
	return depth;
}

// ************************************      迭代 4ms     **************************************
int minDepth(struct TreeNode* root) {
	if (NULL == root) {
		return 0;
	}
	int leftMinDepth = minDepth(root->left);
	int rightMinDepth = minDepth(root->right);
	return 1 + ((leftMinDepth == 0 || rightMinDepth == 0) ? (leftMinDepth + rightMinDepth) : (leftMinDepth < rightMinDepth ? leftMinDepth : rightMinDepth));
}

