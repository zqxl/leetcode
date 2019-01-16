#include<stdio.h>
#include<malloc.h>

struct TreeNode {
	int val;
	struct TreeNode *left = NULL;
	struct TreeNode *right = NULL;

};

// 无限对半拆分，取出每次都取出中间元素作为一个节点将其两侧作为孩子
struct TreeNode* sortedSubArrayToBST(struct TreeNode* nums, int start, int end) {
	int mid=0;
	switch (end - start)
	{
	case 3:
		mid = (end + start - 1) / 2;
		nums[mid].left = &(nums[mid - 1]);
		nums[mid].right = &(nums[mid + 1]);
		return &(nums[mid]);
		break;
	case 2:
		mid = (end + start) / 2;
		nums[mid].left = &(nums[mid - 1]);
		return &(nums[mid]);
		break;
	case 1:
		return &(nums[start]);
		break;
	case 0:
		return NULL;
	default:
		mid = (end + start) / 2;
		nums[mid].left = sortedSubArrayToBST(nums, start, mid);
		nums[mid].right = sortedSubArrayToBST(nums, mid+1, end);
		return &(nums[mid]);
		break;
	}
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	// 首先将每个元素生成树节点,并保存每个树节点到一个数组中
	struct TreeNode *t = (struct TreeNode *) malloc(sizeof(struct TreeNode) * numsSize);
	for (int i = 0; i < numsSize; i++) {
		t[i].val = nums[i];
		t[i].left = NULL;
		t[i].right = NULL;
	}

	/* 可能是因为返回的节点数组中的元素地址，oj无法free()。因此
	借助一个中间变量temp来将节点值替换到节点数组第一个上，然后
	返回节点数组首地址。但是oj仍然free()报错*/
	struct TreeNode temp;
	temp = *sortedSubArrayToBST(t, 0, numsSize);
	t[numsSize / 2] = t[0];
	t[0] = temp;
	t[1].left = &(t[numsSize / 2]);

	return t;
}

int main() {
	int nums[] = { -10,-3,0,5,9, 12, 16 };
	struct TreeNode* tree;
	tree = sortedArrayToBST(nums, 7);
	free(tree);
}