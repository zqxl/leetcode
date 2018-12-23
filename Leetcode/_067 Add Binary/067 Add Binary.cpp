#include<stdio.h>
#include<malloc.h>
#include<string.h>

char* addBinary(char* a, char* b) {
	int la = strlen(a) - 1, lb = strlen(b) - 1, lr = (la > lb ? la : lb) + 1, n=0;
	char c;
	// 如果要存放一个长度为n的字符串，申请内存时长度要+1，以存放结尾的'\0'
	char* r = (char*)calloc(sizeof(char), (lr + 2));
	char* rs = (char*)calloc(sizeof(char), (lr + 1));
	do{
		switch ((int)(a[la] + b[lb] + n)){
			case 48+48:
				n = 0;
				c = '0';
				break;
			case 48+49:
				n = 0;
				c = '1';
				break;
			case 49+49:
				n = 1; 
				c = '0';
				break;
			case 49 + 49+1:
				n = 1;
				c = '1';
		}
		if (la)
			la--;
		else
			a[0] = '0';
		if (lb)
			lb--;
		else
			b[0] = '0';

		r[lr] = c;
		if (lr - 1 > -1){
			rs[lr - 1] = r[lr];
		}
	} while (lr--);
	if (r[0]=='1'){
		free(rs);
		return r;
	}
	else{
		free(r);
		return rs;
	}
}

int main(){
	char a[] = "0";
	char b[] = "0";
	r = addBinary(a, b);
	return 0;
}
