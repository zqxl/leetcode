#include<stdio.h>
#include<malloc.h>
#include<string>
#include<math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements1(struct ListNode* head, int val) {
	struct ListNode *bt = head, *nt = head;
	while (head) {
		if (head->val == val)
			head = head->next;
		else
			break;
	}
	if (!head) return head;

	bt = head;
	nt = head->next;

	while (nt) {
		while (nt && nt->val == val)
			nt = nt->next;
		bt->next = nt;
		bt = nt;
		if (nt)
			nt = nt->next;
	}
	return head;
}

/*
½á¹¹ÇåÎú
*/
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* cur = head;
	struct ListNode* pre = NULL;
	while (cur != NULL){
		if (cur->val == val){
			if (cur == head){
				head = head->next;
				cur = head;
			}
			else{
				pre->next = cur->next;
				cur = pre->next;
			}
		}
		else{
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}
