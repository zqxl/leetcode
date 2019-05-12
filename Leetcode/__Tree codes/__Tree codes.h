#pragma once
#include<stdio.h>
#include<vector>
#include<math.h>
#include<malloc.h>

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct TreeNode *createTreeFromArray(int *nums, int numsSize);
void bt_print(TreeNode *bt);