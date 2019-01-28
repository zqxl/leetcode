#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

int rob1(int* nums, int numsSize) {
	int max1 = 0, max2=0;
	for (int i = 0; i < numsSize; i += 2) {
		max1 += nums[i];
	}
	for (int i = 1; i < numsSize; i += 2) {
		max2 += nums[i];
	}

	return max1 > max2 ? max1 : max2;
}

int max(int x, int y) { return x > y ? x : y; }
int rob(int* nums, int numsSize) {
	if (numsSize == 0) {
		return 0;
	}
	// memo[i] 表示考虑抢劫 nums[i...numsSize-1] 所能获得最大收益（不是说一定从 i 开始抢劫）
	int *memo = (int*)malloc(sizeof(int)*numsSize);
	// 先考虑最简单的情况
	memo[numsSize - 1] = nums[numsSize - 1];
	for (int i = numsSize - 2; i >= 0; i--) {
		// memo[i] 的取值在考虑抢劫 i 号房子和不考虑抢劫之间取最大值
		memo[i] = max(nums[i] + (i + 2 >= numsSize ? 0 : memo[i + 2]), nums[i + 1] + (i + 3 >= numsSize ? 0 : memo[i + 3]));
	}
	return memo[0];
}
