#include<stdio.h>
#include<malloc.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

/*
右对齐然后再对比
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode *a = headA, *b = headB;
	int la = 0, lb = 0;
	// 遍历两个列表确定长度
	while (a) {
		la++;
		a = a->next;
	}
	while (b) {
		lb++;
		b = b->next;
	}

	// 长列表前进到短列表起始位置
	a = headA;
	b = headB;
	int ld = la - lb;
	if (ld > 0) {
		while (ld--) a = a->next;
	}
	else {
		ld = -ld;
		while (ld--) b = b->next;
	}

	// 同时遍历直至相交或行至末尾
	while (1) {
		if (a == NULL) 
			return NULL;
		if (a == b) 
			return a;
		else {
			a = a->next;
			b = b->next;
		}
	}
	//return NULL;
}

/*
12ms
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	int length = 0, lengthR = 0;
	struct ListNode *pA = headA, *pB = headB;
	while (pA&&pB) { length++; pA = pA->next; pB = pB->next; }
	if (pA)
	{
		while (pA) { lengthR++; pA = pA->next; }
		pA = headA; while (lengthR--) { pA = pA->next; }
	}
	else
		pA = headA;
	if (pB)
	{
		while (pB) { lengthR++; pB = pB->next; }
		pB = headB; while (lengthR--) { pB = pB->next; }
	}
	else
		pB = headB;


	//int length=lengthA<=lengthB?lengthA:lengthB;

	//lengthA=lengthA-length;lengthB=lengthB-length;

	while (length--) {
		if (pA->val != pB->val) { pA = pA->next; pB = pB->next; }
		else return pA;
	}
	return NULL;

}

