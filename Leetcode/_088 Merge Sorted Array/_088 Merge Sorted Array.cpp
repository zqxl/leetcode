#include<stdio.h>
#include<malloc.h>
#include <limits.h>

// 辗转找到最小的然后保存到目标
void merge1(int* nums1, int m, int* nums2, int n) {
	int *ma = (int*)malloc(sizeof(int)*(m+n));
	int i = 0, mm = 0, nn = 0;
	if (m == 0) nums1[0] = INT_MAX;
	if (n == 0) nums2[0] = INT_MAX;
	for (i = 0; i < (m + n); i++){
		if (nums1[mm] < nums2[nn]){
			ma[i] = nums1[mm];
			if (mm == m - 1){
				nums1[mm] = INT_MAX;
			}
			else{
				mm++;
			}
		}
		else{
			ma[i] = nums2[nn];
			if (nn == n - 1){
				nums2[nn] = INT_MAX;
			}
			else{
				nn++;
			}
		}
	}
	for (i = 0; i < (m + n); i++){
		nums1[i] = ma[i];
	}
	free(ma);
}

// 0ms 先合并再排序，这是什么排序？？？
void mysort(int *a, int low, int high) {
	if (low >= high) {
		return;
	}
	int i = low;
	int j = high;
	int key = a[i];
	while (i < j) {
		while ((i < j) && (a[j] >= key)) {
			j--;
		}
		a[i] = a[j];
		while ((i < j) && (a[i] <= key)) {
			i++;
		}
		a[j] = a[i];

	}
	a[i] = key;
	mysort(a, low, i - 1);
	mysort(a, i + 1, high);
}

void merge(int* nums1, int m, int* nums2, int n) {

	int i = m + n;
	while (m <= i)
	{
		nums1[m] = nums2[n - 1];
		m++;
		if (n - 1 == 0)
		{
			break;
		}
		n--;

	}
	mysort(nums1, 0, i - 1);
}

int main(){
	int a[] = { 1, 2, 3, 0, 0, 0 };
	int b[] = { 2, 5, 6 };
	merge(a, 3, b, 3);
	return 0;
}