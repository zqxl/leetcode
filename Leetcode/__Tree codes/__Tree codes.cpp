#include<iostream>
#include<vector>
#include<math.h>
#include<malloc.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 由二维数组生成二叉树
struct TreeNode *createTreeFromArray(int *nums, int numsSize) {
	const int numMeansNull = 0;
	struct TreeNode *nodes = (struct TreeNode*)calloc(numsSize, sizeof(struct TreeNode));
	for (int i = 0; i < numsSize; i++) {
		nodes[i].val = nums[i];
		int child = i * 2 + 1;
		nodes[i].left = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
		child = i * 2 + 2;
		nodes[i].right = (child < numsSize && nums[child] != numMeansNull) ? &nodes[child] : NULL;
	}
	return &nodes[0];
}

void calTreeDepth(TreeNode *t);
void setPrintBuffer(TreeNode *t);
int depth = 0, column = 0;
int depthMax = 0;
char **printBuffer = NULL;
void bt_print(TreeNode *bt) {
	// 根据树的大小申请内存
	calTreeDepth(bt);
	int width = (1 << (depthMax - 1)) * 5;
	int height = 1 + (depthMax - 1) * 3;
	printBuffer = (char**)malloc(height *sizeof(char*));
	for (int i = 0; i < depthMax; i++) {
		printBuffer[i] = (char*)malloc(width * sizeof(char));
		memset(printBuffer[i],' ',width);
		printBuffer[i][width - 1] = '/0';
	}


	setPrintBuffer(bt);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", printBuffer[i][j]);
		}
	}

}

void calTreeDepth(TreeNode *t) {
	if (t) {
		depth++;
		depthMax = depthMax < depth ? depth : depthMax;
		calTreeDepth(t->left);
		calTreeDepth(t->right);
		depth--;
	}
}

void setPrintBuffer(TreeNode *t) {
	if (t) {
		depth++;

		printBuffer[(depth - 1) * 3][column * 5 - 3] = t->val + 0x30;

		calTreeDepth(t->left);
		column++;
		calTreeDepth(t->right);
		column--;
		depth--;
	}
}


int main() {
	int nums[] = { 5,4,8,11,0,13,4}; //,7,2,0,0,0,0,5,1 
	struct TreeNode* root = createTreeFromArray(nums, sizeof(nums)/sizeof(nums[0]));
	//dfs(root);
	bt_print(root);

	printf(" /\n");
	printf("/\n");
	for (int i = 0; i < 144; i++) {
		printf("5");
	}
	getchar();
	return 0;
}