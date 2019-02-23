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

/*最大的教训就是用C的话，返回的char**，必须是malloc得来的，刚开始我是直接char bin_tree_paths[100][100]
结果它会说是执行出错，申请之后就没有这样了，其实题目也说了The returned array must be malloced*/
void dfs(struct TreeNode* root, char** bin_tree_paths, int* path, int* returnSize, int depth)
{
	int i = 0;
	path[depth++] = root->val;  //主要是这个depth，depth在每一层的值都不一样的，跳回到哪层，depth就是哪一层的的值
	if (root->left == NULL && root->right == NULL)
	{
		bin_tree_paths[*returnSize] = (char*)malloc(sizeof(char) * 100);
		bin_tree_paths[*returnSize][0] = 0;
		for (i = 0; i < depth - 1; i++)
		{
			sprintf_s(bin_tree_paths[*returnSize], 100, "%s%d->", bin_tree_paths[*returnSize], path[i]); //第一次用了sprintf,挺好用的
		}
		sprintf_s(bin_tree_paths[*returnSize], 100, "%s%d", bin_tree_paths[*returnSize], path[i]); //最后一个不用箭头
		(*returnSize)++;
		return;
	}
	
	if (root->left != NULL)
	{
		dfs(root->left, bin_tree_paths, path, returnSize, depth);
	}

	if (root->right != NULL)
	{
		dfs(root->right, bin_tree_paths, path, returnSize, depth);
	}
	return;  //返回是void类型，其实这一步不写也行
}

char** binaryTreePaths1(struct TreeNode* root, int* returnSize)
{
	int path[100] = { 0 }, depth = 0;
	char** bin_tree_paths = (char**)malloc(sizeof(char*) * 100);
	if (root == NULL)
	{
		return NULL;
	}
	*returnSize = 0;
	dfs(root, bin_tree_paths, path, returnSize, depth);
	return bin_tree_paths;
}


/*
注意leetcode里提交时需要将sprintf_s替换为sprintf。
16ms
先序遍历，没发现一个叶节点就生成一条路径。
保存路径到一个路径栈，当完成一条路径时，将下一个访问节点的高度作为本条路径的开始，之前的路径得以保留
*/
char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
	char** bin_tree_paths = (char**)malloc(sizeof(char*) * 100);
	if (root == NULL)		return NULL;
	*returnSize = 0;

	// 先序遍历
	struct TreeNode *stack[4096];
	int ss = 0;
	// 深度栈，保存每个节点的深度
	int dStack[4096] = { 0 };
	int dss = 0;
	int cd = 0;	//保存当前访问节点的深度
	// 路径栈
	int pathStack[4096] = {0};
	int pss = 0;

	stack[ss++] = root;
	dStack[dss++] = 0;
	while (ss) {
		// 弹栈 访问
		struct TreeNode *ct = stack[--ss];
		cd = dStack[--dss];
		
		// 获取当前节点的高度
		pss = cd;

		// 保存该节点到路径栈
		pathStack[pss++] = ct->val;

		// 孩子入栈，先右后左
		// 如果为叶节点，则生成一条路径
		if (!ct->left && !ct->right) {
			bin_tree_paths[*returnSize] = (char*)calloc(100, sizeof(char));
			for (int i = 0; i < pss-1; i++) {
				sprintf_s(bin_tree_paths[*returnSize], 100, "%s%d->", bin_tree_paths[*returnSize], pathStack[i]);
			}
			sprintf_s(bin_tree_paths[*returnSize], 100, "%s%d", bin_tree_paths[*returnSize], pathStack[pss-1]);

			(*returnSize)++;
		}
		
		if (ct->right) {
			stack[ss++] = ct->right;
			dStack[dss++] = cd + 1;
		}
			
		if (ct->left) {
			stack[ss++] = ct->left;
			dStack[dss++] = cd + 1;
		}
			
	}

	return bin_tree_paths;
}


int main() {
	int b[] = { 1,21,22,321,321,322,322,4321,4322,4,4,4,4,0,0,5,5 };
	struct TreeNode *root;
	root = arrayToTree(b, 17);
	int returnSize;
	char** res = binaryTreePaths(root, &returnSize);
	return 0;
}
