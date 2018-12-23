#include<stdio.h>
long long fa(int x){
	long long  r = 1;
	if (x == 0) return 1;
	do{
		r *= x;
	} while (--x);
	return r;
}
//int c_n_m(int n, int m){
//	return fa(n) / (fa(m)*fa(n - m));
//}

long long a_n_m(int n, int m){
	return fa(n) / fa(n - m);
}

int climbStairs(int n) {
	int i = 0,r=0;
	if (n % 2){
		i = (n - 1) / 2;
	}
	else{
		i = n / 2;
	}

	for (; i >= 0; i--){
		r += a_n_m(n - 2 * i + i, i);
	}
	return r;
}
int main(){
	int r;
	fa(35);
	r = climbStairs(35);
	return 0;
}