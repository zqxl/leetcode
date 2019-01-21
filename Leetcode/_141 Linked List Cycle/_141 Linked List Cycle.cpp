#include<stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

// 使用快慢指针可以实现O(1)空间复杂度
bool hasCycle(struct ListNode *head) {
	struct ListNode *f = head, *l = head;
	if (head == NULL) return false;
	while (f->next != NULL && f->next->next != NULL) {
		f = f->next->next;
		l = l->next;
		if (f == l)
			return true;
	}
	return false;
}

