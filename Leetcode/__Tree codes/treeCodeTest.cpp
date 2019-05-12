#include"__Tree codes.h"

int main() {
	int nums[] = { 15,54,87,-1,-1,2,-1,-1,452,10,20,13,2,150,5, -1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	struct TreeNode* root = createTreeFromArray(nums, sizeof(nums) / sizeof(nums[0]));
	bt_print(root);
	getchar();
	return 0;
}