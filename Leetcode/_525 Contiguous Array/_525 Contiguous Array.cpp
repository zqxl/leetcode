#include<stdio.h>
#include<malloc.h>
#include<memory>
//暴力 超出时间限制 O(N2)
int findMaxLength1(int* nums, int numsSize) {
	int diff = 0, maxLength = 0;
	for (int start = 0; start < numsSize; start++) {
		diff = 0;
		for (int i = start; i < numsSize; i++) {
			diff += (nums[i] == 1 ? 1 : -1);
			if (diff == 0) {
				int length = i - start + 1;
				maxLength = length > maxLength ? length : maxLength;
			}
		}
	}
	return maxLength;
}

/*
改进暴力
每次搜索从最近一次平衡的位置开始搜索，还没调出来。。。
*/
int findMaxLength2(int* nums, int numsSize) {
	int diff = 0, maxLength = 0;
	for (int start = 0; start < numsSize; start++) {
		int iStart = start;
		if (maxLength) {
			diff = (nums[start - 1] == 0 ? 1 : -1);
			iStart = start + maxLength - 1;
		}
		else {
			diff = 0;
		}
		for (int i = iStart; i < numsSize; i++) {
			diff += (nums[i] == 1 ? 1 : -1);
			if (diff == 0) {
				maxLength += i - iStart + 1;
			}
		}
	}
	return maxLength;
}

/*
利用前缀
https://www.cnblogs.com/geek1116/p/9389236.html
执行用时 : 72 ms, 在Contiguous Array的C提交中击败了100.00% 的用户
内存消耗 : 17.3 MB, 在Contiguous Array的C提交中击败了80.00% 的用户
*/
int findMaxLength(int* nums, int numsSize) {
	int *sumMap = (int*)calloc(2*numsSize+1, sizeof(int));
	for(int i=0;i<2 * numsSize + 1;i++){
		sumMap[i] = numsSize + 1;
	}
	sumMap[0 + numsSize] = -1;

	int sum = 0, maxLength = 0;
	for (int i = 0; i < numsSize; i++) {
		sum += (nums[i] == 1 ? 1 : -1);
		if (sumMap[sum + numsSize] == numsSize + 1) {
			sumMap[sum + numsSize] = i;
		}
		else {
			int curLength = i - sumMap[sum + numsSize];
			maxLength = maxLength > curLength ? maxLength : curLength;
		}
	}

	return maxLength;
}

int main() {
	int nums[] = {0,0,1};
	findMaxLength(nums, sizeof(nums) / sizeof(int));
	return 0;
}