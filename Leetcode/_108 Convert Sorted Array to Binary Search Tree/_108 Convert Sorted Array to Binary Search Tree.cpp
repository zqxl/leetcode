#include<stdio.h>
#include<malloc.h>

struct TreeNode {
	int val;
	struct TreeNode *left = NULL;
	struct TreeNode *right = NULL;

};

// ************************************      leetcode oj应该是对每一个TreeNode都进行了free,因此该代码在本地运行无误，但是oj显示free()出错     ***************************
//// 递归对半拆分，取出每次都取出中间元素作为一个节点将其两侧作为孩子
//struct TreeNode* sortedSubArrayToBST1(struct TreeNode* nums, int start, int end) {
//	int mid=0;
//	switch (end - start)
//	{
//	case 3:
//		mid = (end + start - 1) / 2;
//		nums[mid].left = &(nums[mid - 1]);
//		nums[mid].right = &(nums[mid + 1]);
//		return &(nums[mid]);
//		break;
//	case 2:
//		mid = (end + start) / 2;
//		nums[mid].left = &(nums[mid - 1]);
//		return &(nums[mid]);
//		break;
//	case 1:
//		return &(nums[start]);
//		break;
//	case 0:
//		return NULL;
//	default:
//		mid = (end + start) / 2;
//		nums[mid].left = sortedSubArrayToBST(nums, start, mid);
//		nums[mid].right = sortedSubArrayToBST(nums, mid+1, end);
//		return &(nums[mid]);
//		break;
//	}
//}
//
//struct TreeNode* sortedArrayToBST1(int* nums, int numsSize) {
//	// 首先将每个元素生成树节点,并保存每个树节点到一个数组中
//	struct TreeNode *t = (struct TreeNode *) malloc(sizeof(struct TreeNode) * numsSize);
//	for (int i = 0; i < numsSize; i++) {
//		t[i].val = nums[i];
//		t[i].left = NULL;
//		t[i].right = NULL;
//	}
//
//	/* 可能是因为返回的节点数组中的元素地址，oj无法free()。因此
//	借助一个中间变量temp来将节点值替换到节点数组第一个上，然后
//	返回节点数组首地址。但是oj仍然free()报错。
//	因此，我猜测leetcode 的oj是对每一个节点都执行了free()！！！
//	*/
//	struct TreeNode temp;
//	temp = *sortedSubArrayToBST(t, 0, numsSize);
//	t[numsSize / 2] = t[0];
//	t[0] = temp;
//	t[1].left = &(t[numsSize / 2]);
//	return t;
//
//	// 此种写法在住函数调用free()会报错，因为free()只接受动态分配内存的首地址。
//	//return sortedSubArrayToBST(t, 0, numsSize);
//}

// ************************************      4ms通过     ***************************
// 递归对半拆分，取出每次都取出中间元素作为一个节点将其两侧作为孩子
struct TreeNode* sortedSubArrayToBST(int* nums, int start, int end) {
	int mid = 0;
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	struct TreeNode *nodel = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	struct TreeNode *noder = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	switch (end - start)
	{
	case 3:

		mid = (end + start - 1) / 2;

		nodel->val = nums[mid - 1];
		nodel->left = NULL;
		nodel->right = NULL;

		noder->val = nums[mid + 1];
		noder->left = NULL;
		noder->right = NULL;

		root->val = nums[mid];
		root->left = (nodel);
		root->right = (noder);
		return (root);
		break;
	case 2:
		free(noder);
		mid = (end + start) / 2;

		nodel->val = nums[mid - 1];
		nodel->left = NULL;
		nodel->right = NULL;

		root->val = nums[mid];
		root->left = (nodel);
		root->right = NULL;
		return (root);
		break;
	case 1:
		free(noder);
		free(nodel);
		mid = (end + start) / 2;
		root->val = nums[mid];
		root->left = NULL;
		root->right = NULL;
		return (root);
		break;
	case 0:
		return NULL;
	default:
		free(noder);
		free(nodel);
		mid = (end + start) / 2;
		root->val = nums[mid];
		root->left = sortedSubArrayToBST(nums, start, mid);
		root->right = sortedSubArrayToBST(nums, mid + 1, end);
		return (root);
		break;
	}
}

struct TreeNode* sortedArrayToBST1(int* nums, int numsSize) {
	return sortedSubArrayToBST(nums, 0, numsSize);
}

// ************************************      leetcode 4ms代码     **************************************
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	if (numsSize<1)
		return NULL;
	struct TreeNode* tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	tree->left = tree->right = NULL;
	int k = numsSize / 2;
	tree->val = nums[k];
	tree->left = sortedArrayToBST(nums, k);
	tree->right = sortedArrayToBST(nums + k + 1, numsSize - k - 1);
	return tree;
}



int main() {
	char c[10] = "123456789";
	int nums[] = { -1,0,1,2 };
	struct TreeNode* tree;
	tree = sortedArrayToBST(nums, 4);
	// 这里只释放tree是其实不够的。
	free(tree);
	
	return 0;
}
