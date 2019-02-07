#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>
/*
快速排序
*/
void quickSort(int* nums, int s, int e) {
	if (s >= e)
		return;
	int m = nums[(s+e)/2], lo = s, hi = e, t=0;
	while (lo <= hi) {
		while (nums[lo] < m)
			lo++;
		while (nums[hi] > m)
			hi--;
		if(lo<=hi){
			t = nums[lo];
			nums[lo] = nums[hi];
			nums[hi] = t;
			hi--;
			lo++;
		}
	}
	quickSort(nums, s, hi);
	quickSort(nums, lo, e);
}

/*先快排，后查找*/
bool containsDuplicate(int* nums, int numsSize) {
	quickSort(nums, 0, numsSize-1);
	for (int i = 1; i < numsSize; i++) {
		if (nums[i - 1] == nums[i])
			return true;
	}
	return false;
}


/*
暴力解法
*/
bool containsDuplicate1(int* nums, int numsSize) {
	for (int i = 1; i < numsSize; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] == nums[i])
				return true;
		}
	}
	return false;
}

int main() {
	int nums[] = {1,2,3,1};
	containsDuplicate(nums, 4);
	return 0;
}
