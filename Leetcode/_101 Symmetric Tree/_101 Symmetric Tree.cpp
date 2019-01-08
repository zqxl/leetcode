#include<stdio.h>
#include<malloc.h>
/**
* Definition for a binary tree node.*/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

// 思路，将整个树拆分成左右两个树，对两个子树对称分别遍历入栈。最后再弹栈对比。
bool isSymmetric(struct TreeNode* root) {
	TreeNode *stack[4096];
	int size = 0;
	if (root == NULL) 
		return true;
	else {
		stack[0] = root;
		size++;
	}
	
	while (size) {
		// 弹栈
		size--;
		root = stack[size];
		// 访问

	}
}