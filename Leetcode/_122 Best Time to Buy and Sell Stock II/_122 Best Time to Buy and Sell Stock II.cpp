#include<stdio.h>
#include<malloc.h>

int maxProfit(int* prices, int pricesSize) {
	int sum=0;
	for (int i = 1; i<pricesSize; i++) {
		if (prices[i-1] < prices[i]) {
			sum += prices[i] - prices[i - 1];
		}
	}
	return sum;
}