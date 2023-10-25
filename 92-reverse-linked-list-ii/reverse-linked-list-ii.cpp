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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next =head;
        ListNode*prev=dummy;
        int count=1;
        while(count < left){
            prev=prev->next;
            count++;
        }
        ListNode*curr=prev->next;
        ListNode*next=NULL;
        while(count < right){
            next=curr->next;
            curr->next=next->next;
            next->next=prev->next;
            prev->next=next;
            count++;
        }
        return dummy->next;
    }
};