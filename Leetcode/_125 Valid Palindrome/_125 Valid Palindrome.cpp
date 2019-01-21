#include<stdio.h>
#include<string.h>
#include<math.h>
bool isLetter(char c) {
	return ((int)c >= (int)'a' && (int)c <= (int)'z') 
		|| ((int)c >= (int)'A' && (int)c <= (int)'Z');
}
bool isNumber(char c) { return ((int)c >= (int)'0' && (int)c <= (int)'9'); }
bool isValid(char c) { return isLetter(c) || isNumber(c); }
bool isEqual(char x, char y) {
	if (isNumber(x) || isNumber(y))
		return x == y;
	else
		return x == y || abs((int)x - (int)y) == abs((int)'a' - (int)'A');
}
bool isPalindrome(char* s) {
	int st = 0, en = strlen(s)-1;
	while (!isValid(s[st])) {
		st++;
		if (st > en-1) break;
	}
	while (!isValid(s[en])) {
		en--;
		if (en < 1)break;
	}
	while (en > st) {
		if (!isEqual(s[st], s[en])) return false;
		st++;
		en--;
		while (!isValid(s[st])) st++;
		while (!isValid(s[en])) en--;
	}
	return true;
}

int main() {
	char a[10] = "0P";
	int l = 3;
	isPalindrome(a);
	return 0;
}