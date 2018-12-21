#include<stdio.h>
int maxSubArray(int* nums, int numsSize) {
	int max = nums[0], sum = nums[0];
	for (int i = 1; i < numsSize; i++){
		// ！！！关键：如果左侧是负数就舍弃
		sum = sum > 0 ? sum : 0;
		// 叠加当前数字
		sum += nums[i];
		// 更新最大值
		max = max > sum ? max : sum;
	}
	return max;
}

int main(){
	int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	maxSubArray(a, 9);
	return 0;
}
