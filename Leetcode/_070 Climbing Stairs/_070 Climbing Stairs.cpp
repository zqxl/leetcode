#include<stdio.h>

// 排列组合方式 0ms
int c_n_m(int n, int m){
	double r = 1;
	for (int i = 1; i <= m; i++){
		r *= (n + 1.0 - i) / (m + 1 - i);
	}
	if (r-(int)r >0.5)
		return (int)r+1;
	return (int)r;
}
int climbStairs1(int n) {
	int i = 0,r=0;
	if (n % 2){
		i = (n - 1) / 2;
	}
	else{
		i = n / 2;
	}

	for (; i >= 0; i--){
		r += c_n_m(n - 2 * i + i, i);
	}
	return r;
}

// 斐波那契数列
int climbStairs(int n) {
	int i;
	int iCurrent;
	int iFront1;
	int iFront2;
	if (n <= 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}

	iFront2 = 1;
	iFront1 = 2;
	for (i = 0; i < n - 2; i++)
	{
		iCurrent = iFront1 + iFront2;
		iFront2 = iFront1;
		iFront1 = iCurrent;
	}

	return iCurrent;
}

int main(){
	int r;
	r = c_n_m(18, 7);
	r = climbStairs(35);
	return 0;
}