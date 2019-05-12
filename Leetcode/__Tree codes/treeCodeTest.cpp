#include"__Tree codes.h"

int main() {
	int nums[] = { 15,54,87,1,45,20,4,88,452,-1,-1,13,-1,150,5, 6,-1,3,4,5,6,7,8,9,-1,11,12,13,14,15,16 };
	struct TreeNode* root = createTreeFromArray(nums, sizeof(nums) / sizeof(nums[0]));
	bt_print(root);
	getchar();
	return 0;
}