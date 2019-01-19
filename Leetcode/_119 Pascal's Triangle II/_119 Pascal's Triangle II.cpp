#include<stdio.h>
#include<malloc.h>
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* getRow(int rowIndex, int* returnSize) {
	int *rs = (int*)malloc(sizeof(int)*(rowIndex + 1));
	for (int i = 0; i < rowIndex + 1; i++) {
		rs[0] = 1;
		rs[i] = 1;
		*returnSize = i + 1;
		for (int ii = i - 1; ii > 0; ii--) {
			rs[ii] += rs[ii - 1];
		}
	}
	return rs;
}