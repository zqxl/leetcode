#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

bool isPowerOfTwo(int n) {
	while (n != 0) {
		if (n & 1) {
			if (n >> 1 == 0)
				return true;
			else
				return false;
		}
		else {
			n = n >> 1;
		}
	}
	return false;
}

/*Î»²Ù×÷*/
bool isPowerOfTwo(int n) {
	if (n <= 0)
		return false;
	if ((n&n - 1) == 0)
		return true;
	return false;
}

