#include<stdio.h>
#include<malloc.h>

struct TreeNode {
	int val;
	struct TreeNode *left = NULL;
	struct TreeNode *right = NULL;

};
// 数组转树,[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
struct TreeNode* arrayToTree(int* nums, int numsSize) {
	// 数值为nullNode 的元素将被视为此处无孩子
	const int nullNode = 0;
	struct TreeNode* tree = (struct TreeNode*)calloc(0, sizeof(struct TreeNode)*numsSize);
	for (int i = 0; i < numsSize; i++) {
		tree[i].val = nums[i];
		if (i * 2 + 1 < numsSize && nums[i * 2 + 1] != nullNode)  tree[i].left = &(tree[i*2+1]);
		if (i * 2 + 2 < numsSize && nums[i * 2 + 2] != nullNode)  tree[i].right = &(tree[i*2+2]);
	}
	return tree;
}
/*
错误理解 ：层次遍历叶节点，如果最大深度与最小深度差不过1，则为平衡树
*/
bool isBalanced(struct TreeNode* root) {
	// 定义最大最小深度
	int max = 0, min = -1, current=0;
	// 节点地址组成的数组
	struct TreeNode *que[4096];
	// 队列的起始和终止
	int start=0, end=0;
	// 入栈
	if (root) {
		que[end++] = root;
	}
	else return true;
	while (end - start >0) {
		current++;
		// 记录本层最左最右的节点位置
		int left_nest = start, right_nest  = end;
		for (int i = left_nest; i < right_nest; i++) {
			if (que[i]->left)
				que[end++] = que[i]->left;
			else {
				// 更新叶节点
				max = current;
				if (min == -1) min = current;
				if (max - min > 1) return false;
			}
			if (que[i]->right) 
				que[end++] = que[i]->right; 
			else {
				// 更新叶节点
				max = current;
				if (min == -1) min = current;
				if (max - min > 1) return false;
			}
		}
		start = right_nest;
	}
	return true;
}

int main() {
	int nums[] = { 1,2,2,3,3,3,3,4,4,4,4,4,4,0,0,5,5 };
	isBalanced(arrayToTree(nums, 17));
	return 0;
}