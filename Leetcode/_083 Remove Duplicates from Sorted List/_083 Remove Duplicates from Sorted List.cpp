#include<stdio.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head) return head;
	struct ListNode *r = head, *hot = head;
	while (r->next){
		r = r->next;
		if (hot->val != r->val){
			hot->next = r;
			hot = r;
		}
		else{
			hot->next = NULL;
		}
	}
	return head;
}

int main(){

	return 0;
}