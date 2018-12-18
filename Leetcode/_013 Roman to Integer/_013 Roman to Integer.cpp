#include<stdio.h>
int romanToInt1(char* s) {
	int i = 0, result = 0;
	while (1){
		switch (s[i]){
		case 'I':
			if (s[i + 1] == 'V'){
				i++;
				result += 4;
			}
			else if (s[i + 1] == 'X'){
				i++;
				result += 9;
			}
			else{
				result += 1;
			}
			break;
		case 'X':
			if (s[i + 1] == 'L'){
				i++;
				result += 40;
			}
			else if (s[i + 1] == 'C'){
				i++;
				result += 90;
			}
			else{
				result += 10;
			}
			break;
		case 'C':
			if (s[i + 1] == 'D'){
				i++;
				result += 400;
			}
			else if (s[i + 1] == 'M'){
				i++;
				result += 900;
			}
			else{
				result += 100;
			}
			break;
		case 'V':
			result += 5;
			break;
		case 'L':
			result += 50;
			break;
		case 'D':
			result += 500;
			break;
		case 'M':
			result += 1000;
			break;
		case '\0':
			return result;
		}
		i++;
	}
	return result;
}

//稍做改进，主要是去掉了变量i，直接使用取值符*
int romanToInt2(char* s) {
	int result = 0;
	do{
		switch (*s){
		case 'I':
			if (*(s + 1) == 'V'){
				s++;
				result += 4;
			}
			else if (*(s + 1) == 'X'){
				s++;
				result += 9;
			}
			else{
				result += 1;
			}
			break;
		case 'X':
			if (*(s + 1) == 'L'){
				s++;
				result += 40;
			}
			else if (*(s + 1) == 'C'){
				s++;
				result += 90;
			}
			else{
				result += 10;
			}
			break;
		case 'C':
			if (*(s + 1) == 'D'){
				s++;
				result += 400;
			}
			else if (*(s + 1) == 'M'){
				s++;
				result += 900;
			}
			else{
				result += 100;
			}
			break;
		case 'V':
			result += 5;
			break;
		case 'L':
			result += 50;
			break;
		case 'D':
			result += 500;
			break;
		case 'M':
			result += 1000;
			break;
		case '\0':
			return result;
		}
	} while (*s++);
	return result;
}

// 大佬程序
int romanToInt(char* s) {
	//建立查询表
	int map[128];
	map[0] = 0;
	map['I'] = 1;
	map['V'] = 5;
	map['X'] = 10;
	map['L'] = 50;
	map['C'] = 100;
	map['D'] = 500;
	map['M'] = 1000;

	char prev = 0;
	int r = 0;

	do{
		//对于两个字符组成的4,9,40,90,400,900，对第一个字符加，对第二个字符减
		if (map[prev] < map[*s])
			r -= map[prev];
		else
			r += map[prev];
		prev = *s;
	} while (*s++);

	return r;
}

int main(){
	int result = 0;
	result = romanToInt("VII");
	return result;
}