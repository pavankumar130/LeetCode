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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>cretical;
        int cnt = 2;
        ListNode * prev = head;
        head = head -> next;

        while(head != NULL && head -> next != NULL){
            if(prev -> val < head ->val && head -> next -> val < head ->val){
                cretical.push_back(cnt);
            }
            
            if(prev -> val > head ->val && head -> next -> val > head ->val){
                cretical.push_back(cnt);
            }

            cnt++;
            prev = head;
            head = head -> next;
        }

        int n = cretical.size();
        if(n < 2){
            return {-1, -1};
        }

        int maxi = cretical[n - 1] - cretical[0];
        int mini = INT_MAX;
        for(int i = 1; i < n; i++){
            mini = min(mini, cretical[i] - cretical[i - 1]);
        }
        
        return {mini, maxi};
    }
};