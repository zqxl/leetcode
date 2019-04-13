#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
#include<set>
#include<algorithm>
using namespace std;

int fun(int x) {
	return x + 1;
}

int main() {
	int a = 123;
	int(*b)(int) = fun;
	int c = b(3);
	return 0;
}