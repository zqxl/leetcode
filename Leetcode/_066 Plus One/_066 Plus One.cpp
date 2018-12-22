#include<stdio.h>
#include<malloc.h>
/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int* r = (int*)malloc(digitsSize * sizeof(int) );
	int c=1, i=0;
	for (i = digitsSize-1; i > -1; i--){
		r[i] = (digits[i] + c) % 10;
		c = (digits[i] + c) / 10;
	}
	if (c){
		int* r2 = (int*)malloc((digitsSize+1) * sizeof(int));
		r2[0] = 1;
		for (i = 0; i < digitsSize;i++){
			r2[i + 1] = r[i];

		}
		free(r);
		*returnSize = digitsSize + 1;
		return r2;
	}
	else{
		*returnSize = digitsSize;
		return r;
	}
}

int main(){
	int input[] = {1,2,9};

	return 0;;
}