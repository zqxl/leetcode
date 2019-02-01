#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

bool isIsomorphic(char* s, char* t) {
	char ss1[256] = { 0 };
	char ss2[256] = { 0 };
	while (*s) {
		if (ss1[(int)(*s)] == 0) {
			ss1[(int)(*s)] = *t;
		}
		else {
			if (ss1[(int)(*s)] != *t)
				return false;
		}

		if (ss2[(int)(*t)] == 0) {
			ss2[(int)(*t)] = *s;
		}
		else {
			if (ss2[(int)(*t)] != *s)
				return false;
		}

		s++;
		t++;
	}
	return true;
}

