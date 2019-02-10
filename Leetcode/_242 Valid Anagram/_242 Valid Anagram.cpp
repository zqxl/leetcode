#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

bool isAnagram(char* s, char* t) {
	int sum1[256] = { 0 }, sc=0;
	char *ss = s;
	
	while (*s) {
		sum1[*s]++;
		s++;
		sc++;
	}

	int sum2[256] = { 0 }, tc=0;
	char *tt = t;
	while (*t) {
		sum2[*t]++;
		t++;
		tc++;
	}

	if (tc != sc)
		return false;

	for (int i = 0; i < sc; i++) {
		if (sum1[(ss[i])] != sum2[(ss[i])]) {
			return false;
		}
	}

	return true;
}

/*
在扫描第二个字符串时进行比较

bool isAnagram(char* s, char* t) {
	short map[256];
	int i = 0;
	while (i < 256) {
		map[i++] = 0;
	}

	i = 0;
	while (s[i] != '\0') {
		map[s[i]]++;
		i++;
	}

	int len = i;
	int cnt = 0;
	i = 0;
	while (t[i] != '\0') {
		if (map[t[i]] == 0) {
			return false;
		}
		else
			map[t[i]]--;
		cnt++;
		i++;
	}
	if (cnt != len)
		return false;
	return true;
}


*/

int main() {
	isAnagram("abcda", "dcbaa");
	return 0;
}
