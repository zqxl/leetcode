#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
执行用时344 ms。内存46MB。
分情况处理：

if (blacklistSize*1.0 / N >= 0.6) 
	建立白名单，pick时从白名单抽取
else
	重复生成随机数，直到该数不在黑名单里
*/
int cmp(const void *x, const void *y) {
	return *((int*)x) - *((int*)y);
}

long unsigned int randbillion() {
	long unsigned int res = 0;
	long unsigned int y = 1;
	for (int i = 0; i < 3; i++) {
		res += rand()*y;
		y *= 10000;
	}
	return res % 1000000000;
}

typedef struct {
	int *blacklist;
	int blacklistSize;
	int N;
	bool bigBlack;
	int *whitelist;
	int whitelistSize;
} Solution;

Solution* solutionCreate(int N, int* blacklist, int blacklistSize) {
	Solution *res = (Solution*)malloc(sizeof(Solution));
	res->blacklist = blacklist;
	res->blacklistSize = blacklistSize;
	res->N = N;

	srand((unsigned)time(NULL));
	qsort(blacklist, blacklistSize, sizeof(int), cmp);

	//如果随机命中率小于0.3，就建立白名单，pick时从白名单抽取
	if (blacklistSize*1.0 / N >= 0.6) {
		res->bigBlack = true;
		res->whitelistSize = (N - blacklistSize);
		res->whitelist = (int *)malloc(res->whitelistSize * sizeof(int));
		// 初始化白名单
		int numIndex = 0, num = 0, curIndex = 0, cur=0;
		while( num < res->N) {
			if (curIndex < blacklistSize) {
				cur = blacklist[curIndex];
			}
			else {
				cur = N;
			}
				
			for (; num < cur; num++) {
				res->whitelist[numIndex] = num;
				numIndex++;
			}
			curIndex++;
			num++;
		}
	}
	else {
		res->bigBlack = false;
		res->whitelist = (int *)malloc(1 * sizeof(int));
	}

	return res;
}

int solutionPick(Solution* obj) {
	long unsigned int res;
	int i = 0;
	if (obj->bigBlack) {
		res = obj->whitelist[(randbillion()%obj->whitelistSize)];
		return res;
	}
	else {
		while (1) {
			res = randbillion() % obj->N;
			if(bsearch(&res, obj->blacklist, obj->blacklistSize, sizeof(int), cmp) == NULL)
				return res;
		}
	}
		
}

void solutionFree(Solution* obj) {
	free(obj->whitelist);
	free(obj);
}
/**
* Your Solution struct will be instantiated and called as such:
* struct Solution* obj = solutionCreate(N, blacklist, blacklistSize);
* int param_1 = solutionPick(obj);
* solutionFree(obj);
*/


int main() {
	int blacklist[] = { 2,3,4,5,7,8,9};
	Solution* s = solutionCreate(1,blacklist,0);//sizeof(blacklist)
	int res = solutionPick(s);
	return 0;
}





/*


typedef struct {
int *black; int blacksize;
int N;
} Solution;

int comp(const void*a, const void*b) { return *(int*)a - *(int*)b; }

Solution* solutionCreate(int N, int* blacklist, int blacklistSize) {
Solution* obj = (Solution*)malloc(sizeof(Solution));
qsort(blacklist, blacklistSize, sizeof(int), comp);
obj->black = blacklist;
obj->blacksize = blacklistSize;
obj->N = N;
srand(time(0));
return obj;
}

int solutionPick(Solution* obj) {
int cur = rand() % (obj->N - obj->blacksize);
int i = 0;
for (i = 0; i<obj->blacksize; i++) {
if (obj->black[i] <= cur) {
cur++;
}
} return cur;
}

void solutionFree(Solution* obj) { free(obj); }


*/
