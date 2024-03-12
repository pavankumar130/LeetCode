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
    void solve(ListNode* head, vector<int>&arr){
        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int>arr;
        solve(head,arr);

        vector<int>temp;

        int i = 0;
        while(i < arr.size()){
            int sum = 0;
            int j = i;
            bool flag = true;
            while(j < arr.size()){
                sum += arr[j];
                if(sum == 0){
                    flag = false;
                    break;
                }
                j++;
            }

            if(!flag){
                i = j + 1;
            }
            else{
                temp.push_back(arr[i]);
                i++;
            }
        }

        ListNode* res = NULL;
        ListNode* tail = NULL;
        for(auto it:temp){
            if(res == NULL){
                res = new ListNode(it);
                tail = res;
            }
            else{
                tail->next = new ListNode(it);
                tail = tail->next;
            }
        }
        if(tail != NULL)tail -> next = NULL;
        return res;
    }
};