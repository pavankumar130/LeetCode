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
    ListNode* solve(ListNode* list, int cnt){
        while(cnt){
            cnt--;
            list = list->next;
        }
        return list;
    }
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* a_pointer = solve(list1, a-1);
        ListNode* b_pointer = solve(list1, b);

        ListNode* tail = list2;

        while(tail != NULL && tail->next != NULL){
            tail = tail->next;
        }

        a_pointer ->next = list2;
        tail ->next = b_pointer ->next;

        return list1;
    }
};