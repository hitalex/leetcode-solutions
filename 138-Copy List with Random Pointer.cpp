#include <iostream>

using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) return NULL;
		// 在原来的链表中，每个节点后跟一个与之相同的节点
		RandomListNode* p = head;
		do{
			// 这种方式可保证重建所有的节点，包括最后一个
			RandomListNode *q = p->next;
			p->next = new RandomListNode(p->label);
			p->next->next = q;
			p = q;
		} while (p != NULL);
		// 对新添加的节点中的random指针进行赋值
		p = head;
		RandomListNode* r;
		while (p != NULL){
			r = p->next;
			r->random = p->random == NULL ? NULL : p->random->next;
			p = r->next;
		}
		// 将两个链表分开
		p = head;
		RandomListNode* new_head = head->next;
		r = head->next;
		while (r->next != NULL){
			p->next = r->next;
			r->next = p->next->next;
			r = r->next;
			p = p->next;
		}
		p->next = NULL; // 设置原来的链表的最后一个节点的next值为空

		return new_head;
	}
};