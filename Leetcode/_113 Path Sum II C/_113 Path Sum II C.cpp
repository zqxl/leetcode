#include<stdio.h>
#include"__Tree codes.h"
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


#if 0
#define MAX 1000
int path[MAX] = { 0 };
int pathsize = 0;
int csum = 0;
int target = 0;

int* retsize;
int** retcsize;

void dfs(struct TreeNode *t, int **ret) {
	if (!t) {
		return;
	}

	csum += t->val;
	path[pathsize++] = t->val;


	if (!t->left && !t->right) {
		if (csum != target) {
			pathsize--;
			csum -= t->val;
			return;
		}
		else {
			// ±£´æÂ·¾¶£»
			(*retcsize)[*retsize] = pathsize;
			int *cpath = (int *)malloc(sizeof(int)*pathsize);
			for (int i = 0; i<pathsize; i++) {
				cpath[i] = path[i];
			}

			ret[*retsize] = cpath;
			(*retsize)++;
		}
	}

	dfs(t->left, ret);
	dfs(t->right, ret);

	csum -= t->val;
	pathsize--;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes) {
	target = sum;
	retsize = returnSize;
	*retsize = 0;

	*returnColumnSizes = (int *)malloc(sizeof(int)*MAX);
	int **ret = (int **)malloc(sizeof(int *)*MAX);

	retcsize = returnColumnSizes;
	dfs(root, ret);
	return ret;
}

#else
#define MAX 1000
int gSum = 0;
int** ret;

int tmp[MAX];

void dfs(int target, int current, struct TreeNode* p, int pos, int* colSize) {
	if (!p)return;

	tmp[pos] = p->val;
	if (!p->left && !p->right && p->val + current == target) {
		ret[gSum] = malloc(sizeof(int)*(pos + 1));
		for (int i = 0; i <= pos; i++) {
			ret[gSum][i] = tmp[i];
		}
		colSize[gSum] = pos + 1;
		gSum++;
	}

	if (p->left)
		dfs(target, current + p->val, p->left, pos + 1, colSize);
	if (p->right)
		dfs(target, current + p->val, p->right, pos + 1, colSize);
}


/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes) {
	*returnColumnSizes = malloc(sizeof(int)*MAX);
	ret = malloc(sizeof(int*)*MAX);
	gSum = 0;
	dfs(sum, 0, root, 0, *returnColumnSizes);
	*returnSize = gSum;
	return ret;
}
#endif

int main() {
	int nums[] = { 5,4,8,11,0,13,4,7,2,0,0,5,1 };
	//int nums[] = { 1 };
	struct TreeNode* root = createTreeFromArray(nums, sizeof(nums)/sizeof(nums[0]), 0);
	bt_print(root);
	int returnSize;
	int *returnColumnSizes;
	pathSum(root, 22, &returnSize, &returnColumnSizes);
	return 0;
}