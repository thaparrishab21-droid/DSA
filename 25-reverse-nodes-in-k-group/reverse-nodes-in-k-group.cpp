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
    ListNode* kthele(ListNode* node,int k){
        while(node && k>0){
            node=node->next;
            k--;
        }
        return node;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode();
        dummy->next=head;
        ListNode* groupprev=dummy;
        while(true){
            ListNode* kth=kthele(groupprev,k);
            if(!kth) break;
            ListNode* groupnext=kth->next;
            ListNode* prev=groupnext;
            ListNode* curr=groupprev->next;
            for(int i=0;i<k;i++){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            ListNode* temp=groupprev->next;
            groupprev->next=kth;
            groupprev=temp;
        }
        return dummy->next;
    }
};