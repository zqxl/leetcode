#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<map>
#include<vector>
#include<stdlib.h>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	map<int, int> intMap;
	int N;
	int white_N;
	Solution(int N, const vector<int>& blacklist) {
		this->N = N;
		this->white_N = N - blacklist.size(); // 白名单的个数
											  //cout<<"white_N:"<<white_N<<' ';
		set<int> intS;
		for (int i = 0; i<blacklist.size(); i++) 
			intS.insert(blacklist[i]);
		int j = N - 1;
		for (int i = 0; i<blacklist.size(); i++) {
			if (blacklist[i]<white_N) {
				while (intS.count(j) != 0)j--;
				intMap[blacklist[i]] = j; j--;
				//cout<<"#"<<blacklist[i]<<','<<j<<')';
			}
		}
	}
	int pick() {
		int tmp = random() % (this->white_N);
		if (intMap.find(tmp) != intMap.end()) {
			return intMap[tmp];
		}
		else {
			return tmp;
		}

	}
};