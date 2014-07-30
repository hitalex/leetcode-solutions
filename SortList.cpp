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
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* mid = this->findMiddle(head);
        ListNode* right_head = this->sortList(mid->next);
        
        mid->next = NULL;
        ListNode* left_head = this->sortList(head);
        
        return this->mergeList(left_head, right_head);
    }
    
    ListNode* mergeList(ListNode* left, ListNode* right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        ListNode* head = new ListNode(0); // dummy head
        ListNode* curr = head;
        while(left != NULL && right != NULL){
            // assume acending order
            if(left->val <= right->val){
                curr->next = left;
                curr = left;
                left = left->next;
            }else{
                curr->next = right;
                curr = right;
                right = right->next;
            }
        }
        
        if(left == NULL){
            curr->next = right;
        }else{
            curr->next = left;
        }
        
        return head->next;
    }    
    
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = slow->next;
        // find the middle position in a linked list
        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    void printList(ListNode* head){
        ListNode* p = head;
        while(p != NULL){
            cout << p->val << endl;
            p = p->next;
        }
    }
    
    ListNode* createList(int a[], int n){
        ListNode* head = new ListNode(a[0]);
        ListNode* p = head;
        for(int i=1; i<n; ++i){
            p->next = new ListNode(a[i]);
            p = p->next;
        }
        
        return head;
    }
};

int main(){
    Solution solution = Solution();
    int a1[3] = {2,3,6};
    int a2[3] = {4,5,9};
    ListNode* l1 = solution.createList(a1, 3);
    ListNode* l2 = solution.createList(a2, 3);
    
    //ListNode* m = solution.mergeList(l1, l2);
    //solution.printList(m);
    int a3[6] = {2,3,6,4,5,9};
    ListNode* l3 = solution.createList(a3, 6);
    l3 = solution.sortList(l3);
    solution.printList(l3);
    
    return 1;
}
