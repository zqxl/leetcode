#include<stdio.h>
#include<malloc.h>
typedef struct {
	int *st;
	int hot;
	int min;
} MinStack;

int minElement(int* nums, int size) {
	if (size == 0) return 0x7fffffff;
	int min = nums[0];
	for (int i = 1; i < size; i++) {
		if (min > nums[i]) min = nums[i];
	}
	return min;
}
/** initialize your data structure here. */
MinStack* minStackCreate(int maxSize) {
	MinStack *s = (MinStack*)malloc(sizeof(MinStack));
	s->hot = -1;
	s->min = (int)0x7fffffff;
	s->st = (int*)malloc(sizeof(int) * maxSize);
	return s;
}

void minStackPush(MinStack* obj, int x) {
	obj->hot++;
	obj->st[obj->hot] = x;
	if (obj->min > x) {
		obj->min = x;
	}
}

void minStackPop(MinStack* obj) {
	if (obj->st[obj->hot] == obj->min) {
		obj->min = minElement(obj->st, obj->hot);
	}
	
	obj->hot--;
}

int minStackTop(MinStack* obj) {
	return obj->st[obj->hot];
}

int minStackGetMin(MinStack* obj) {
	return obj->min;
}

void minStackFree(MinStack* obj) {
	free(obj->st);
}

/**
* Your MinStack struct will be instantiated and called as such:
* struct MinStack* obj = minStackCreate(maxSize);
* minStackPush(obj, x);
* minStackPop(obj);
* int param_3 = minStackTop(obj);
* int param_4 = minStackGetMin(obj);
* minStackFree(obj);
*/



/* 12ms
每次入栈时都将当前的最小值紧随其后一同入栈，出栈时也是将两个一起出栈，实现常数时间获得当前最小值
typedef struct {
int *nums;
int top;
} MinStack;

MinStack* minStackCreate(int maxSize) {
	MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
	stack->top = -1;
	stack->nums = (int*)malloc(2 * maxSize * sizeof(int));
	return stack;
}

void minStackPush(MinStack* obj, int x) {
	if (obj->top == -1) {
		(obj->nums)[++(obj->top)] = x;
		(obj->nums)[++(obj->top)] = x;
	}
	else {
		int MIN = x > (obj->nums)[(obj->top)] ? (obj->nums)[(obj->top)] : x;
		(obj->nums)[++(obj->top)] = x;
		(obj->nums)[++(obj->top)] = MIN;
	}
}

void minStackPop(MinStack* obj) {
	(obj->nums)[(obj->top)--];
	(obj->nums)[(obj->top)--];

}

int minStackTop(MinStack* obj) {
	return (obj->nums)[(obj->top) - 1];
}

int minStackGetMin(MinStack* obj) {
	return (obj->nums)[(obj->top)];
}

void minStackFree(MinStack* obj) {
	obj->top = -1;
}
*/

int main() {
	int temp;
	MinStack* obj = minStackCreate(6);
	minStackPush(obj, 2);
	

	minStackPush(obj, 1);
	temp = minStackGetMin(obj);

	minStackPop(obj);

	temp = minStackGetMin(obj);

	temp = minStackTop(obj);
	temp = minStackGetMin(obj);
	minStackFree(obj);
	return 0;
}