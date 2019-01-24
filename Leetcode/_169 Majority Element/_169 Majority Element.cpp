#include<stdio.h>
#include<malloc.h>

// 计数法,对于负数无能为力
int majorityElement1(int* nums, int numsSize) {
	int a[4096] = { 0 };
	int i;
	for (i = 0; i < numsSize; i++) {
		if (++a[nums[i]])
			break;
	}
	return nums[i];
}
/*
减而治之思想,每当发现一个子序列中首元素个数占该子序列的一半时，就将该序列舍弃
*/
// 
int majorityElement(int* nums, int numsSize) {
	int maj;
	for (int i = 0, c = 0; i < numsSize; i++) {
		if (c == 0) {
			maj = nums[i];
			c = 1;
		}
		else {
			if (maj == nums[i]) c++;
			else c--;
		}
	}
	return maj;
}


int main() {
	int a[] = { 3,2,3 };
	majorityElement(a, 3);
	return 0;
}
