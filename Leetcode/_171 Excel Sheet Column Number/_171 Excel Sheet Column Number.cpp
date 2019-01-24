#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>
int titleToNumber(char* s) {
	int sl = strlen(s), rs=0;
	for (int i = 0; i < sl; i++) {
		rs += pow(26, sl - i-1)*(int)(s[i] - 'A' + 1);
	}
	return rs;
}
