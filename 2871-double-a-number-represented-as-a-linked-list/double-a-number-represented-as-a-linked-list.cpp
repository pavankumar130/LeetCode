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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = reverse(head);

        int rem = 0;
        ListNode* res = NULL;
        ListNode* tail = NULL;

        while(temp != NULL || rem){
            int sum = rem;
            if(temp != NULL){
                sum += (temp->val)*2;
                temp = temp->next;
            }

            if(res == NULL){
                res = new ListNode(sum%10);
                tail = res;
            }
            else{
                tail->next = new ListNode(sum%10);
                tail = tail->next;
            }
          rem = sum/10;
        }

        return reverse(res);
    }
};