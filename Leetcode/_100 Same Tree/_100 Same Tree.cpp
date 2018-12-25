#include<stdio.h>
#include<malloc.h>
/**
* Definition for a binary tree node.*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 迭代方式，利用栈结构对两个树进行遍历
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	TreeNode *stack_p = (TreeNode*)malloc(sizeof(TreeNode) * 4096);
	int size_p = 0;
	TreeNode *stack_q = (TreeNode*)malloc(sizeof(TreeNode) * 4096);
	int size_q = 0;
	int i = 0;
	while (1){
		stack_p[i] = *p;
	}
	return 0;
}

// 递归 原文：https ://blog.csdn.net/xishirujin_/article/details/51235733 
bool isSameTree1(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL&&q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	return p->val == q->val&&isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

}

int main(){
	TreeNode *a = (TreeNode*)malloc(sizeof(TreeNode) * 3);

	return 0;
}
