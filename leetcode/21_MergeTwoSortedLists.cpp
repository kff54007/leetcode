#include <iostream>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode head(0);
	auto end = &head;
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			end->next = l1;
			end = l1;
			l1 = l1->next;
		}
		else {
			end->next = l2;
			end = l2;
			l2 = l2->next;
		}
	}
	if (l1 == NULL)
		end->next = l2;
	else
		end->next = l1;
	return head.next;
}
//int main()
//{
//	return 0;
//}