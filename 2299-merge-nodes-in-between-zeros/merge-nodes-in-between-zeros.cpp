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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = NULL;
        ListNode * tail = NULL;

        while(head != NULL){
            int sum = 0;
            head = head->next;
            while(head != NULL && head ->val != 0){
                sum += head ->val;
                head = head->next;
            }

            if(sum){
                if(res == NULL){
                    res = new ListNode(sum);
                    tail = res;
                }
                else{
                    tail ->next = new ListNode(sum);
                    tail = tail->next;
                }
            }
        }

        if(tail){
            tail ->next =  NULL;
        }

        return res;
    }
};