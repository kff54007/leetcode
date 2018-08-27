#include <iostream>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
	//if(head == NULL)
	//    return NULL;
	auto tListNode = ListNode(0);
	auto tHead = &tListNode;
	tHead->next = head;

	auto second = tHead;
	for (int i = 0; i < n; i++)
		head = head->next;

	while (head != NULL)
	{
		head = head->next;
		second = second->next;
	}
	second->next = second->next->next;
	return tHead->next;
}

//int main()
//{
//	auto t = ListNode(1);
//	removeNthFromEnd(&t, 1);
//	return 0;
//}