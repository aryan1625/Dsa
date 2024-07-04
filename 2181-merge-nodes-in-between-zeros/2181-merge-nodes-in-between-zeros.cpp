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
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        ListNode* temp = head;
        ListNode* newHead = new ListNode();
        ListNode* tempNew = newHead;
        int curr = 0;
        while(temp!=NULL){
            if(temp->val!=0){
                curr+=temp->val;
            }
            else{
                if(curr!=0){
                    tempNew->val = curr;
                    curr = 0;
                    if(temp->next!=NULL){
                        tempNew->next = new ListNode();
                        tempNew = tempNew->next;
                    }
                }
            }
            temp = temp->next;
        }
        
        return newHead;
    }
};