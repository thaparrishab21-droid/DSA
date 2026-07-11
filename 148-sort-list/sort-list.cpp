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
    ListNode* sortList(ListNode* head) {
        if(head == NULL||head->next==NULL)
            return head;
        vector<int>sorted;
        ListNode* temp=head;
        while(temp!=NULL){
            sorted.push_back(temp->val);
            temp=temp->next;
        }
        sort(sorted.begin(),sorted.end());
        ListNode* h1 = new ListNode(sorted[0]);
        temp=h1;
        for(int i=1;i<sorted.size();i++){
            ListNode* nxt = new ListNode(sorted[i]);
            temp->next=nxt;
            temp=nxt;
        }
        return h1;
    }
};