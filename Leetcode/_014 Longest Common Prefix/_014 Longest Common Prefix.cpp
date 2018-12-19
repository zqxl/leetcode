#include<stdio.h>
#include<malloc.h>
#include<cstring>
//两个循环解决
char* longestCommonPrefix1(char** strs, int strsSize) {
	int count=0;
	char* r = (char*)(char*)calloc(strlen(strs[0]), sizeof(char));
	do{
		for (int i = 1; i < strsSize; i++){
			if (!*(strs[i] + count) || *(strs[i] + count) != *(strs[0] + count)){
				return r;
			}
		}
		r[count] = *(strs[0] + count);
		count++;
	} while (*(strs[0] + count));
	return r;
}

// 大佬4ms程序，但是测试用例为{ "fl", "fl", "fl" }等时，将无法通过。
char* longestCommonPrefix(char** strs, int strsSize) {
	int i = 0, j = 0, len;
	char *common;
	if (strsSize <= 1)return strs[0];
	len = strlen(strs[0]);
	common = (char*)malloc(sizeof(char)*len);
	while (true){
		for (i = 0; i<strsSize - 1; i++){
			if (strs[i][j] != strs[i + 1][j]){
				common[j] = '\0';
				return common;
			}
		}
		common[j] = strs[0][j];
		j++;
	}
}

int main(){
	char* s[] = { "flo", "flo", "flo" };
	char* r=NULL;
	r = longestCommonPrefix(s, 3);
	return 0;
}