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
    ListNode* removeNodes(ListNode* head) {
        
        ListNode* temp = reverse(head);
        ListNode* res = NULL;
        ListNode* tail = NULL;

        stack<ListNode*>st;

        while(temp != NULL){
            while(!st.empty() && temp != NULL && st.top()->val > temp->val){
                temp = temp->next;
            }

            if(temp != NULL){
                st.push(temp);
                temp = temp->next;
            }
        }

        while(!st.empty()){
            if(res == NULL){
                res = st.top();
                tail = st.top();
                st.pop();
            }
            else{
                tail->next = st.top();
                tail = tail->next;
                st.pop(); 
            }
        }
        tail->next = NULL;

        return res;
    }
};