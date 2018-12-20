#include<stdio.h>
#include<cstring>
// 先用蛮力方法 4ms
int strStr1(char* haystack, char* needle) {
	int i = 0, j = 0;
	if (!haystack[0] && !needle[0])
		return 0;
	while (1){
		for (j = 0; 1; j++){
			if (!haystack[i + j] && needle[j]){
				return -1;
			}
			else if (!needle[j]){
				return i;
			}
			else if (haystack[i + j] != needle[j]){
				break;
			}
		}
		i++;
	}
}

// 0ms范例,并未使用KMP算法
int strStr(char* haystack, char* needle)
{
	if (strlen(needle) == 0)
		return 0;
	int h = strlen(needle);
	int k = strlen(haystack);
	int i = 0, j = 0;
	while (i != k)
		if (haystack[i] != needle[j])
		{
			i = i - j + 1;
			j = 0;
		}
		else
		{
			j += 1;
			if (j == h)
				return i - h + 1;
			i += 1;
		}
	return -1;
}

int main(){
	int r = 0;
	r = strStr("cebcef", "cef");
	return 0;
}