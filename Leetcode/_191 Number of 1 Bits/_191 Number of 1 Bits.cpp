#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

int hammingWeight(uint32_t n) {
	int rs = 0;
	for (int i = 0; i < 32; i++) {
		if ((n >> i) & 1) {
			rs++;
		}
	}
	return rs;
}
