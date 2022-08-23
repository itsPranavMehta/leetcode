/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head,*rev=nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            ListNode* prev=slow;
            slow=slow->next;
            prev->next=rev;
            rev=prev;            
        }
        
        if(fast)    slow=slow->next;
        while(slow){
            if(slow->val!=rev->val) return 0;
            slow=slow->next;
            rev=rev->next;
        }
        return 1;
    }
};