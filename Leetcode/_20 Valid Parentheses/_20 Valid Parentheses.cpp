#include<stdio.h>

//使用素数乘除判断配对
bool isValid(char* s) {
	float map[256] = { 0 }, r = 1;
	map['('] = 3;
	map[')'] = 1.0 / 3;
	map['['] = 5;
	map[']'] = 1.0 / 5;
	map['{'] = 7;
	map['}'] = 1.0 / 7;

	do{
		r *= map[*s];
		if (r != (int)r) 
			return false;
	} while (*s++);
	return true;
}

int main(){
	bool r;
	r = isValid("()[]");
	return r;
}