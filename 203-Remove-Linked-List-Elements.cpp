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
    ListNode* removeElements(ListNode* head, int val) {
        // add a dummy head pointer
        ListNode* p = new ListNode(-1);
        p->next = head;
        head = p;
        
        p = head;
        ListNode* q = head->next;
        while(q != NULL){
            if(q->val == val){
                p->next = q->next;
                delete q;
                q = p->next;
            }else{
                p = q;
                q = p->next;
            }
        }
        
        return head->next;
    }
};
