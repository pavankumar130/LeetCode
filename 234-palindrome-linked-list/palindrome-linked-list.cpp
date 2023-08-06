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
        ListNode*slow=head;
        ListNode*fast=head;
        while( fast !=NULL && fast->next !=NULL ){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*h=NULL;
        while(slow !=NULL){
            ListNode*next=slow->next;
            slow->next=h;
            h=slow;
            slow=next;
        }
        while(h !=NULL){
            if(head->val != h->val){
                return false;
            }
            h=h->next;
            head=head->next;
        }
        return true;
    }
};