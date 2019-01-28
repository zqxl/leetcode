#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

bool isPrime(int x) {
	for (int i = 2; i < x; i++) {
		if (x%i == 0)
			return false;
	}
	return true;
}
int countPrimes(int n) {
	if (n < 3) return 0;
	int rs = 1;
	for (int i = 3; i < n; i++) {
		if (isPrime(i))
			rs++;
	}
	return rs;
}



