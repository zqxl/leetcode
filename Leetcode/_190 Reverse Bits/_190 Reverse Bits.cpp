#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

uint32_t reverseBits(uint32_t n) {
	int rs = 0;
	for (int i = 0; i < 32; i++) {
		rs += ((n >> i) & 1)<<(31-i);
	}
	return rs;
}