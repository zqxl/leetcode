#include<stdio.h>
int removeDuplicates(int* nums, int numsSize) {
	int hot=0;
	if (!numsSize) return 0;
	for (int i = 1; i<numsSize; i++){
		if (nums[i] != nums[hot]){
			nums[++hot] = nums[i];
		}
	}
	return ++hot;
}

int main(){
	int size, nums[] = {1,1,2};
	size = removeDuplicates(nums, 3);
	return 0;
}