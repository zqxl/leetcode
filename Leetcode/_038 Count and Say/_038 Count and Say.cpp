#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<memory.h>
#include<cstring>

char* countAndSay1(int n) {
	char* s1 = (char*)calloc(4096 * 2, sizeof(char));
	char* s2 = (char*)calloc(4096 * 2, sizeof(char));
	int i=0,count=0,ii=0;
	char cc;
	if (n < 1)
		return "";
	s1[0] = '1';
	s2[0] = '1';
	while (--n){
		i = 1;
		cc = s1[0];
		count = 1;
		while (1){
			if (s1[i] == cc){
				count++;
			}
			else if (!s1[i]){
				s2[ii] = (char)(0x30 + count);
				s2[ii + 1] = cc;
				ii = 0;
				break;
			}
			else if (s1[i] != cc){
				s2[ii] = (char)(0x30+count);
				s2[ii + 1] = cc;
				count = 1;
				cc = s1[i];
				ii = ii + 2;
			}
			i++;
		}
		s1 = (char*)((int)s1 ^ (int)s2);
		s2 = (char*)((int)s1 ^ (int)s2);
		s1 = (char*)((int)s1 ^ (int)s2);
	}
	free(s2);
	return s1;
}

// 0ms·¶Àý
char* countAndSay(int n) {
	char* buff1 = (char*)malloc(sizeof(char) * 4096 * 2);
	char* buff2 = (char*)malloc(sizeof(char) * 4096 * 2);
	memset(buff1, 0, 4096 * 2);
	memset(buff2, 0, 4096 * 2);
	buff1[0] = '1';
	while (--n){
		buff1 = (char*)((int)buff1 ^ (int)buff2);
		buff2 = (char*)((int)buff1 ^ (int)buff2);
		buff1 = (char*)((int)buff1 ^ (int)buff2);
		memset(buff1, 0, 1024);
		int i, j;
		i = j = 0;
		int len = strlen(buff2);
		do{
			char now = buff2[i];
			int c = 0;
			for (++i, ++c; (i<len) && (buff2[i] == now); ++i, ++c);
			j += sprintf(buff1 + j, "%d", c);
			buff1[j++] = now;
		} while (i<len);
	}
	//char* ret=(char*)malloc(sizeof(char)*strlen(buff1));
	//memcpy(ret,buff1,strlen(buff1));
	return buff1;
}

int test(){
	int i = 0;
	return i++;
}
int main(){
	int j = 0;
	//countAndSay(20);
	j = test();
	return 0;
}