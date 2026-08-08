class Solution {
public:

    // Merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (l1 != NULL && l2 != NULL) {

            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }

            temp = temp->next;
        }

        // If l1 still has nodes
        if (l1 != NULL) {
            temp->next = l1;
        }

        // If l2 still has nodes
        if (l2 != NULL) {
            temp->next = l2;
        }

        return dummy->next;
    }


    // Merge K sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* ans = NULL;

        for (int i = 0; i < lists.size(); i++) {

            ans = mergeTwoLists(ans, lists[i]);

        }

        return ans;
    }
};