#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode *head) {
		if (head == NULL || head->next == NULL){
			return;
		}
		// find the mid point of the linked list
		ListNode* slow = head;
		ListNode* fast = slow->next;
		// find the middle position in a linked list
		while (slow != NULL && fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}

		// 设链表有n个元素，如果n为偶数，那么mid指向第n/2个元素，如果n为奇数，那么mid指向n/2+1个元素
		ListNode *mid = slow;
		stack<ListNode*> s;
		ListNode* p = mid;
		while (p != NULL){
			s.push(p); // 顺序访问，并将其放入栈中
			p = p->next;
		}
		
		p = head;
		ListNode *q;
		while (!s.empty()){
			q = s.top();
			s.pop();
			q->next = p->next;
			p->next = q;
			p = q->next;
		}
		// 根据链表中元素的个数的奇偶进行处理
		if (p == NULL)
			q->next = NULL; // last item
		else
			p->next = NULL; // last item
	}
};

int main(){
	
}