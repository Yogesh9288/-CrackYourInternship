class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        while (cur) {
            if (cur->val != val) {
                temp->next = cur;
                temp = temp->next;
            }
            cur = cur->next;
        }
        temp->next = NULL;
        return dummy->next;
    }
};
