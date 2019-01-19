#include<stdio.h>
#include<malloc.h>

int maxProfit1(int* prices, int pricesSize) {
	int min = (int)0xfffffff, max = -1, max_pro = 0;
	for (int i = 0; i < pricesSize; i++) {
		if (prices[i] < min) {
			min = prices[i];
			max = -1;
		}
		if (prices[i]>max) {
			max = prices[i];
			max_pro = max_pro > max - min ? max_pro : max - min;
		}	
	}
	return max_pro;
}

int maxProfit(int* prices, int pricesSize) {
	if (prices == NULL || pricesSize <= 0) return 0;

	int max = 0, min = prices[0];
	for (int i = 1; i < pricesSize; i++)
	{
		if (prices[i] - min > max)
			max = prices[i] - min;
		if (prices[i] < min)
			min = prices[i];
	}
	return max;
}

int main() {
	int a[] = { 7,1,5,3,6,4 };
	maxProfit(a, 6);
	return 0;
}