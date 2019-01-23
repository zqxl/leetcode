#include<stdio.h>
#include<malloc.h>

char* convertToTitle(int n) {
	char stack[4096];
	int ss = 0;
	int n_res = 0;
	//n--;
	while (n>26){
		// 取余
		n_res = n % 26;
		if (n_res) {
			// 最低位字母入栈
			stack[ss++] = (char)('A' + n_res-1);
			// 取整
			n = n / 26;
		}
		else {
			// 最低位字母入栈
			stack[ss++] = 'Z';
			// 取整
			n = (n / 26)-1;
		}
			
	}
	stack[ss++] = (char)('A' + n-1);

	char *re = (char*)malloc(sizeof(char) * (ss+1));
	int i = 0;
	// 出栈
	for (i = 0; --ss+1;i++) {
		re[i] = stack[ss];
	}
	re[i] = '\0';
	return re;
}

int main() {
	convertToTitle(27);
	return 0;
}
