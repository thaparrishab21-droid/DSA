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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* h1=head;
        ListNode* h2=head->next;
        ListNode* temp=h2;
        while(temp!=NULL && temp->next!=NULL){
            h1->next=temp->next;
            temp->next=temp->next->next;
            h1=h1->next;
            temp=temp->next;
        }
        h1->next=h2;
        return head;
    }
};