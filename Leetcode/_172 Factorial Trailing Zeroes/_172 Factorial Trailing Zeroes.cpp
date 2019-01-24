#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>
/*
8ms
*/
int trailingZeroes(int n) {
	int rs = 0;
	int i = 1;
	while (n >= pow(5, i)) {
		rs += n / pow(5, i);
		i++;
	}
	return rs;
}
