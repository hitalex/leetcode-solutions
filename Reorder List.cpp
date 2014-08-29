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

		// ��������n��Ԫ�أ����nΪż������ômidָ���n/2��Ԫ�أ����nΪ��������ômidָ��n/2+1��Ԫ��
		ListNode *mid = slow;
		stack<ListNode*> s;
		ListNode* p = mid;
		while (p != NULL){
			s.push(p); // ˳����ʣ����������ջ��
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
		// ����������Ԫ�صĸ�������ż���д���
		if (p == NULL)
			q->next = NULL; // last item
		else
			p->next = NULL; // last item
	}
};

int main(){
	
}