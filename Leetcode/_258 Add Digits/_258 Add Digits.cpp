#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

int addDigits(int num) {
	int t = num;
	while (num>9) {
		num = 0;
		while (t) {
			num += t % 10;
			t = t / 10;
		}
		t = num;
	}
	return num;
}

