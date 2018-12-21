#include<stdio.h>
#include<string.h>

int lengthOfLastWord(char* s) {
	int i = strlen(s) - 1, count = 0;
	while (1){
		if (i<0)
			return 0;
		else if (s[i] != ' '){
			count++;
			i--;
			break;
		}
		i--;
	}

	while (s[i] != ' ' && i>=0){
		i--;
		count++;
	}
	return count;
}

int main(){
	char s[] = "day";
	lengthOfLastWord(s);
	return 0;
}