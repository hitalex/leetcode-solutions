#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL){
			return false;
		}
		ListNode* p = head;
		ListNode* q = head;
		bool flag = false;
		while (p != NULL && q != NULL && q->next != NULL){
			p = p->next;
			q = q->next->next;
			// if there is a loop, then p and q must meet somewhere in the link
			if (p == q){
				flag = true;
				break;
			}
		}

		if (flag)
			return true;
		
		return false;
	}

	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL){
			return false;
		}
		ListNode* p = head;
		ListNode* q = head;
		bool flag = false;
		while (p != NULL && q != NULL && q->next != NULL){
			p = p->next;
			q = q->next->next;
			// if there is a loop, then p and q must meet somewhere in the link
			if (p == q){
				flag = true;
				break;
			}
		}
		// there is no loop
		if (! flag)
			return NULL;

		// make q to start at head
		q = head;
		while (true){
			if (p == q)
				break;
			q = q->next;
			p = p->next;
		}

		return p;
	}
};