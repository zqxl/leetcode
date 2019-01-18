#include<stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left = NULL;
     struct TreeNode *right =NULL;
};

// 迭代法 4ms
int max(int x, int y) { return x > y ? x : y; }
int maxDepth1(struct TreeNode* root) {
	if (root == NULL) return 0;
	else if (root->left == NULL & root->right == NULL) return 1;
	else if (root->left && root->right) return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
	else if (root->left == NULL) return maxDepth(root->right) + 1;
	else if (root->right == NULL) return maxDepth(root->left) + 1;
	return 0;
}

// 层次遍历法
int maxDepth(struct TreeNode* root) {
	// 创建一直二叉树指针数组作为队列
	struct TreeNode *qu[10240];
	// 创建一个相同结构的数组来记录每个入队元素的深度,dc记录当前出队元素的深度,max记录最大的深度
	int d[10240], dc,max = 0;
	// 队列起始和终止下标，s为第一个元素e-1为最后一个元素
	int s = 0, e = 0;
	if (root == NULL) return 0;
	else {
		d[e] = 1;
		qu[e++] = root;
	}
	while (e - s > 0) {
		// 出队
		dc = d[s];
		root = qu[s++];

		max = dc > max ? dc : max;
		
		// 左右孩子入队
		if (root->left) {
			d[e] = dc+1;
			qu[e++] = root->left;
		}
		if (root->right) {
			d[e] = dc + 1;
			qu[e++] = root->right;
		}
	}
	return max;
}

