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
        vector<int> ans(2,-1);
        ListNode* temp = head->next;
        int val = head->val;
        int i = 0,mini = 1e9,maxi = -1e9;
        int prev = -1;
        int last = -1;
        while(temp->next!=NULL){
            if((temp->val<val && temp->val<temp->next->val)||(temp->val>val && temp->val>temp->next->val)){
                if(prev!=-1){
                    mini = min(mini,i-prev);
                }else{
                    last = i;
                }
                prev = i;
            }
            val = temp->val;
            temp = temp->next;
            i++;
        }
        if(mini==1e9)return ans;
        maxi = prev-last;
        ans[0] = mini;
        ans[1] = maxi;
        return ans;
    }
};