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
int solve(ListNode* head){
    int n=0;
    while(head != NULL){
        n++;
        head=head->next;
    }
    return n;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=solve(head);
        int ind=(size-n);
        if(ind == 0){
            return head->next;
        }
        ListNode*temp=head;
        while(ind > 1){
           temp=temp->next;
           ind--;
        }
        if(temp->next != NULL){
          temp->next=temp->next->next;
        }
        else{
            temp->next=NULL;
        }
        return head;
    }
};