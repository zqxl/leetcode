#include<stdio.h>
#include<malloc.h>
char* countAndSay(int n) {
	char* s1 = (char*)calloc(2 * n, sizeof(char));
	char* s2 = (char*)calloc(2 * n, sizeof(char));
	char* c = s1;
	char* p = s2;
	char* t = NULL;
	int i=0,count=0,ii=0;
	char cc;

	if (n < 1)
		return "";
	s1[0] = '1';
	s2[0] = '1';
	while (n--){
		i = 1;
		cc = p[0];
		count = 1;
		while (1){
			if (p[i] == cc){
				count++;
			}
			else if (!p[i]){
				c[ii] = (char)count;
				c[ii + 1] = cc;
				break;
			}
			else if (p[i] != cc){
				c[ii] = (char)(0x30+count);
				c[ii + 1] = cc;
				count = 0;
				cc = p[i];
				ii = ii + 2;
			}
			i++;
		}
		t = p;
		p = c;
		c = t;
	}
	return p;
}

int main(){
	countAndSay(3);
	return 0;
}