/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 空链表
        if(head == NULL)   
            return NULL;
        
        // 只有一个元素    
        if(head->next == NULL){
            TreeNode* p = new TreeNode(head->val);
            p->left = NULL;
            p->right = NULL;
            return p;
        }
        
        // 有多个元素: 找到中间元素
        ListNode* mid = break_list(head);
        TreeNode* p = new TreeNode(mid->val);
        p->left = sortedListToBST(head);
        p->right = sortedListToBST(p->next);
    }
    
    // 找到中间元素，并从中间断开链表
    // 该链表只有包含两个元素
    ListNode* break_list(ListNode* head){
        ListNode* p = head;
        ListNode* q = p;
        ListNode* pre = NULL; // p节点的pre节点
        while(q && q->next){
            pre = p;
            p = p->next;
            q = q->next->next;
        }
        
        // 假设链表有n个节点，1）如果n为偶数，那么结束时q=NULL, p在n/2+1位置，pre处于n/2位置
        // 如果n为奇数，q->next=NULL，p在n/2+1位置，pre处于n/2位置
        pre->next = NULL;
        
        return p;
    }
    
};
