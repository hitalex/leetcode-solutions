/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
            
        // add dummy head
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        
        int index = 0;
        p = head;
        while(index < m -1){
            p = p->next;
            index ++;
        }
        // 此时p指向m的前一个节点
        ListNode* pre = p;
        ListNode* q = pre->next; // 翻转列表的第一个元素
        ListNode* tail = q;
        // index始终指向p的位置
        p = q->next;
        index += 2;
        while(index <= n){
            ListNode* tmp = p->next;
            p->next = q;
            q = p;
            p = tmp;
            index ++;
        }
        
        pre->next = q;
        tail->next = p;
        
        return head->next;
    }
};
