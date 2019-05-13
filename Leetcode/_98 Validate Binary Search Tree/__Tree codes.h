/*二叉树生成与打印程序*/
#pragma once
#include<stdio.h>
#include<vector>
#include<math.h>
#include<malloc.h>

// 数组中数值等与此值的元素将被视为二叉树中的空节点
#define numMeansNull -1

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从nums数组生成二叉树。数组元素须为小于等与999的正整数，空节点以宏定义numMeansNull表示。
struct TreeNode *createTreeFromArray(int *nums, int numsSize);
// 打印二叉树bt
void bt_print(TreeNode *bt);