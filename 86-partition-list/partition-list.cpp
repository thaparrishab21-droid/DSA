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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        vector<int>ans;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                ans.push_back(temp->val);
            }
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val>=x){
                ans.push_back(temp->val);
            }
            temp=temp->next;
        }
        ListNode* dummy=new ListNode(-1);
        temp=dummy;
        for(int i=0;i<ans.size();i++){
            ListNode* curr=new ListNode(ans[i]);
            temp->next=curr;
            temp=temp->next;
        }
        return dummy->next;
    }
};