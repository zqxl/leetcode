#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

bool isPrime(int x, int* ra, int rs) {
	for (int i = 0; ra[i] * ra[i] <= x; i++) {
		if (x%ra[i] == 0)
			return false;
	}
	return true;
}
int countPrimes1(int n) {
	if (n < 3) return 0;

	int *ra = (int*)malloc(sizeof(int)*n);
	int rs = 1;
	ra[0] = 2;
	for (int i = 3; i < n; i=i+2) {
		if (isPrime(i, ra, rs))
			ra[rs++] = i;
	}
	return rs;
}
/*
欧拉法
https://blog.csdn.net/u012102306/article/details/71407105
*/
// 执行用时为 8 ms 的范例
int countPrimes(int n) {
	if (n <= 2) return 0;
	int i, count = 1, j;
	bool *nums = (bool*)malloc(sizeof(bool)*n);
	//默认都置为质数
	for (int i = 3; i<n; i += 2) {
		nums[i] = false;
	}
	// 对于每个质数小于根号n的每个质数，将其所有的整数倍置为合数
	for (i = 3; i*i <= n; i += 2)
		if (!nums[i])
			for (j = i*i; j<n; j += i)
				nums[j] = true;
	// 统计质数个数
	for (i = 3; i<n; i += 2)
		if (!nums[i]) count++;

	return count;
}

int main() {
	countPrimes(10);
	return 0;
}



