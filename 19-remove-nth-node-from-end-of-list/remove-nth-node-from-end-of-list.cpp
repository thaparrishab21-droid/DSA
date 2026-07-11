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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return nullptr;
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(len<n) return head;
        int posi=len-n;
        if(posi == 0){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int k=0;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(k!=posi){
            k++;
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
};