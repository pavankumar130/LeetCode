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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        int n=1;
        ListNode* temp=head;
        while(temp->next != NULL){
            n++;
            temp=temp->next;
        }
        temp->next=head;
        k=k%n;
        int ind =n-k;
        for(int i=1;i<ind;i++){
            head=head->next;
        }
        ListNode*ans=head->next;
        head->next=NULL;
        return ans;
    }
};