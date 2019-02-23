#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

bool isUgly(int num) {
	if (num <= 0) return false;
	while (num >= 5) {
		if (num % 5 == 0) {
			num /= 5;
		}
		else if (num % 3 == 0) {
			num /= 3;
		}
		else if (num % 2 == 0) {
			num /= 2;
		}
		else {
			return false;
		}
	}
	return true;
}

