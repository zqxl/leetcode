#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 数组转树,[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
struct TreeNode* arrayToTree(int* nums, int numsSize) {
	// 数值为nullNode 的元素将被视为此处无孩子
	const int nullNode = 0;
	struct TreeNode* tree = (struct TreeNode*)calloc(0, sizeof(struct TreeNode)*numsSize);
	for (int i = 0; i < numsSize; i++) {
		tree[i].val = nums[i];
		if (i * 2 + 1 < numsSize && nums[i * 2 + 1] != nullNode)
			tree[i].left = &(tree[i * 2 + 1]);
		else
			tree[i].left = NULL;
		if (i * 2 + 2 < numsSize && nums[i * 2 + 2] != nullNode)
			tree[i].right = &(tree[i * 2 + 2]);
		else
			tree[i].right = NULL;
	}
	return tree;
}

struct TreeNode* invertTree(struct TreeNode* root) {
	struct TreeNode* stack[4096];
	int size = 0;

	struct TreeNode* cache[4096];
	int cacheSize = 0;
	// 如果根节点非空，根节点入栈
	if (!root)
		return NULL;
	stack[size++] = root;

	// 延当前访问节点的左子树至底，依次入栈
	while (stack[size - 1]->left) {
		stack[size++] = stack[size - 1]->left;
	}

	// 中序遍历
	while (size) {
		// 出栈并访问
		cache[cacheSize++] = stack[--size];
		// 转向其右子树
		if (cache[cacheSize-1]->right) {
			stack[size++] = cache[cacheSize - 1]->right;

			// 延当前访问节点的左子树至底，依次入栈
			while (stack[size - 1]->left) {
				stack[size++] = stack[size - 1]->left;
			}
		}
	}

	// 翻转
	for (int i = 0; i < cacheSize; i++) {
		struct TreeNode* temp = cache[i]->left;
		cache[i]->left = cache[i]->right;
		cache[i]->right = temp;
	}

	return root;
}

/* 递归解法
struct TreeNode* invertTree(struct TreeNode* root) {
	if (!root)
		return NULL;

	struct TreeNode* temp = root->right;
	root->right = invertTree(root->left);
	root->left = invertTree(temp);

	return root;
}
*/

int main() {
	int nums[] = { 4,2,7,1,3,6,9 };
	struct TreeNode* tree = arrayToTree(nums, 7);
	tree = invertTree(tree);
	return 0;
}