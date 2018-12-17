#include <stdio.h>

//192ms
bool isPalindrome1(int x) {
	long result = 0;
	int y =x;
	if (x < 0)
		return false;
	for (int i = 0; i < 10; i++){
		result = result * 10 + x % 10;
		x = x / 10;
		if (x == 0)
			break;
	}
	return result - y == 0;
}

//108ms·¶Àý
bool isPalindrome(int x) {
	int result = 0;
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;
	for (int i = 0; i < 10; i++){
		result = result * 10 + x % 10;
		x = x / 10;
		if (x <= result)
			break;
	}
	return result == x || result / 10 == x;
}

int main(){
	bool b;
	b = isPalindrome(1234321);
	return b;
}