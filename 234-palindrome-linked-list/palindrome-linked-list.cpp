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
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast != NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* newh=NULL;
    while(slow !=NULL){
        ListNode* next=slow->next;
        slow->next=newh;
        newh=slow;
        slow=next;
    }
    while(newh != NULL){
       if(head->val != newh->val){
           return false;
       }
       newh=newh->next;
       head=head->next;
    }
    return true;
    }
};