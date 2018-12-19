#include<stdio.h>
#include<malloc.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;
	struct ListNode* r = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* rp = r;

	// 排除特殊情况以防访问溢出
	if (!l1 && !l2)
		return NULL;
	else if (!l1)
		return l2;
	else if (!l2)
		return l1;
	while (1){
		if (p1->val < p2->val){
			rp->next = p1;
			if (p1->next)
				p1 = p1->next;
			else{
				rp = rp->next;
				rp->next = p2;
				return r->next;
			}
		}
		else{
			rp->next = p2;
			if (p2->next)
				p2 = p2->next;
			else{
				rp = rp->next;
				rp->next = p1;
				return r->next;
			}
		}
		rp = rp->next;
	}
}