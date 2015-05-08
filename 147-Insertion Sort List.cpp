
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;        
        }
        // add a dummy head
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        head = dummy_head;
        
        ListNode* curr = head->next->next;
        ListNode* tail = head->next;
        tail->next = NULL;
        
        // elements between head and tail are already sorted
        ListNode* next_curr = NULL;
        while(curr != NULL){
            ListNode* pre = head;
            ListNode* p = head->next;
            next_curr = curr->next;
            while(p != NULL){
                if(curr->val < p->val){
                    pre->next = curr;
                    curr->next = p;
                    break;
                }
                pre = p;
                p = pre->next;
            }
            // add to last
            if(p == NULL){
                pre->next = curr;
                curr->next = NULL;
            }
            
            curr = next_curr;
        }
        
        return head->next;
    }
};
