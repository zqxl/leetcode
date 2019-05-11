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
int width = 0;
char **printBuffer = NULL;
void bt_print(TreeNode *bt) {
	// 根据树的大小申请内存
	calTreeDepth(bt);
	width = 3 * ((1 << (depthMax - 1)) * 2 - 1);
	int height = 1 + (depthMax - 1) * 3;
	printBuffer = (char**)malloc(height *sizeof(char*));
	for (int i = 0; i < height; i++) {
		printBuffer[i] = (char*)malloc(width * sizeof(char));
		memset(printBuffer[i],' ',width);
		printBuffer[i][width - 1] = '\0';
	}

	depth = 0;
	column = width / 2;
	setPrintBuffer(bt);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			printf("%c", printBuffer[i][j]);
		}
		printf("\n");
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

		int val = t->val;
		for (int i = 0; i < 3; i++) {
			printBuffer[(depth - 1) * 3][column+1-i] = val%10 + 0x30;
			val /= 10;
		}

		int step = (1<<(depthMax-depth-1))*3;
		column -= step;
		setPrintBuffer(t->left);
		column += step;
		column += step;
		setPrintBuffer(t->right);
		column -= step;
		depth--;
	}
}


int main() {
	int nums[] = { 15,54,87,231,0,93,4,7,452,0,0,13,2,555,11, 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 }; //
	struct TreeNode* root = createTreeFromArray(nums, sizeof(nums)/sizeof(nums[0]));
	bt_print(root);
	getchar();
	return 0;
}