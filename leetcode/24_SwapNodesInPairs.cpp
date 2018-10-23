
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
class Solution {
public:
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
		
	};
	ListNode * swapPairs(ListNode* head) {
		ListNode **pNext = &head, *a = NULL, *b = NULL;
		while ((a = *pNext) && (b = a->next))
		{
			a->next = b->next;
			b->next = a;
			*pNext = b;
			pNext = &(a->next);
		}
		return head;
	}
	ListNode* swapPairsRecursive(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		auto a = head->next;
		head->next = swapPairs(a->next);
		a->next = head;
		return a;
	}
};