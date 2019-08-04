/*二叉树生成与打印程序*/
#pragma once
#include<stdio.h>
#include<math.h>
#include <memory.h>
#include<malloc.h>



// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从nums数组生成二叉树。数组元素须为小于等与999的正整数，空节点以numMeansNull表示。
struct TreeNode *createTreeFromArray(int *nums, int numsSize,int numMeansNull);
// 打印二叉树bt
void bt_print(TreeNode *bt);