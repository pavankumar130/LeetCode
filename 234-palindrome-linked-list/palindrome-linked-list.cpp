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
    ListNode* reverse(ListNode* head){
        ListNode* temp = NULL;

        while(head != NULL){
            ListNode* next = head->next;
            head->next = temp;
            temp = head;
            head = next;
        }
        return temp;

    }
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* rev = reverse(slow);

        while(rev != NULL){
            if(rev->val != head->val){
                return false;
            }
            rev = rev->next;
            head = head->next;
        }
        return true;
    }
};