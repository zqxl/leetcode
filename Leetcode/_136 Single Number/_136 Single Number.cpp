#include<stdio.h>

int singleNumber(int* nums, int numsSize) {
	int rs = 0;
	for (int i = 0; i < numsSize; i++) {
		rs ^= nums[i];
	}
	return rs;
}

