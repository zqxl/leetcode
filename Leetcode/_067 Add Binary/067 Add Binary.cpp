#include<stdio.h>
#include<malloc.h>
#include<string.h>

char* addBinary(char* a, char* b) {
	int la = strlen(a) - 1, lb = strlen(b) - 1, lr = (la > lb ? la : lb)+1, c = 0, n = 0;
	char* r = (char*)malloc(sizeof(char)*(lr+2));
	char* rs = (char*)malloc(sizeof(char)*(lr+1));
	memset(r, '\0', lr + 2);
	memset(r, '\0', lr + 1);
	do{
		switch ((int)(a[la] + b[lb] + n)){
			case 48+48:
				n = 0;
				c = 0;
				break;
			case 48+49:
				n = 0;
				c = 1;
				break;
			case 49+49:
				n = 1; 
				c = 0;
				break;
			case 49 + 49+1:
				n = 1;
				c = 1;
		}
		if (la){
			la--;
		}
		else{
			a[0] = '0';
		}
		if (lb){
			lb--;
		}
		else{
			b[0] = '0';
		}


		r[lr] = (char)(48 + c);
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
	char a[] = "10000011";
	char b[] = "111000";
	int sl = strlen(a);
	char* r = (char*)calloc(sizeof(char),100);
	r = addBinary(a, b);
	return 0;
}
