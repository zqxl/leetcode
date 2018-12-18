#include<stdio.h>
#include<malloc.h>

//使用素数乘除判断配对,方案失败。因为一个整数无法表示左括号的位置，就无法解决"[(])"在一类问题
bool isValid1(char* s) {
	double map[256] = { 0 }, r = 1;
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

// 使用一个字符串模仿栈结构，后进先出
// 可以通过所有测试用例，但是注意如果不重新分配内存，如果输入字符串有大于4096个未配对的左括号，将会访问到未分配的内存。
bool isValid(char* s) {
	int N = 64;
	char* z = NULL;
	z =(char*)malloc(N*sizeof(char));
	// 栈的长度，z[p]即可访问栈顶。
	int p=-1;
	while (*s){
		if (*s == '(' || *s == '[' || *s == '{'){
			p++;
			// 如果越界了就重新分配内存
			if (p > N - 1){
				N *= 2;
				z = (char*)realloc(z, N *sizeof(char));
			}
			z[p]=*s;
		}
		else{
			if (p < 0) 
				return false;
			if ((int)z[p] == *s - 1 || (int)z[p] == *s - 2){
				p--; 
			}
			else{
				return false;
			}
		}
		s++;
	}
	return p == -1;
}




int main(){
	bool r;
	r = isValid("[]()");
	return r;
}