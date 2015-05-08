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
		// ��ԭ���������У�ÿ���ڵ���һ����֮��ͬ�Ľڵ�
		RandomListNode* p = head;
		do{
			// ���ַ�ʽ�ɱ�֤�ؽ����еĽڵ㣬�������һ��
			RandomListNode *q = p->next;
			p->next = new RandomListNode(p->label);
			p->next->next = q;
			p = q;
		} while (p != NULL);
		// ������ӵĽڵ��е�randomָ����и�ֵ
		p = head;
		RandomListNode* r;
		while (p != NULL){
			r = p->next;
			r->random = p->random == NULL ? NULL : p->random->next;
			p = r->next;
		}
		// ����������ֿ�
		p = head;
		RandomListNode* new_head = head->next;
		r = head->next;
		while (r->next != NULL){
			p->next = r->next;
			r->next = p->next->next;
			r = r->next;
			p = p->next;
		}
		p->next = NULL; // ����ԭ������������һ���ڵ��nextֵΪ��

		return new_head;
	}
};