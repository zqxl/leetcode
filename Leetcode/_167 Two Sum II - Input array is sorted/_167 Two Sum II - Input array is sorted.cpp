#include<stdio.h>
#include<malloc.h>


/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int searchNum1(int *nums, int s, int e, int t) {
	for (int i = s; i < e; i++) {
		if (nums[i] == t) return i;
	}
	return -1;
}
/*
4ms 二分查找
*/
//二分查找
int searchNum(int *nums, int s, int e, int t) {
	int m;
	while (e>s) {
		m = (s + e) / 2;
		if (t < nums[m]) 
			e = m;
		else if (nums[m] < t) 
			s = m+1;
		else 
			return m;
	}
	return -1;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int *index = (int *)malloc(sizeof(int)*2);
	for (int i = 0; i < numbersSize; i++) {
		index[1]= searchNum(numbers, i+1, numbersSize, target - numbers[i]);
		if (index[1] != -1){
			index[0] = i+1;
			index[1]++;
			*returnSize = 2;
			return index;
		}
	}
	*returnSize = 0;
	return index;
}

/*
0ms 两头查找，O(n)时间
*/
int* twoSum1(int* numbers, int numbersSize, int target, int* returnSize) {
	int i = 0, j = numbersSize - 1;
	while (numbers[i] + numbers[j] != target)
	{
		if (numbers[i] + numbers[j] > target)
			j--;
		else i++;
	}
	*returnSize = 2;
	int* index = (int*)malloc(2 * sizeof(int));
	index[0] = i + 1;
	index[1] = j + 1;
	return index;
}


int main() {
	int a[] = { 2,7,9,10,11,15 };
	int returnSize=0;
	returnSize = searchNum(a, 0, 6, 2);
	twoSum(a, 4, 9, &returnSize);
	return 0;
}


