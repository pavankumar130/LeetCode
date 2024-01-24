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
    ListNode* merge(ListNode* ptr1, ListNode* ptr2){
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(ptr1 && ptr2){
            if(ptr1->val < ptr2->val){
                if(head == NULL){
                    head = ptr1;
                    tail = ptr1;
                }
                else{
                    tail->next = ptr1;
                    tail = tail->next;
                }
                ptr1 = ptr1->next;
            }
            else{
                if(head == NULL){
                    head = ptr2;
                    tail = ptr2;
                }
                else{
                    tail->next = ptr2;
                    tail = tail->next;
                }
                ptr2 = ptr2->next;
            }
        }

        if(ptr1){
            tail->next = ptr1;
        }
        if(ptr2){
            tail->next = ptr2;
        }

        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;
        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode* ptr1 = sortList(head);
        ListNode* ptr2 = sortList(slow);

        return merge(ptr1, ptr2);
    }
};