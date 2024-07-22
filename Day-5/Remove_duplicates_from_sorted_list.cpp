class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;
        ListNode* cur = head;
        ListNode* nhead = head;
        ListNode* node = nhead;
        int data = head->val;
        while (cur) {
            if (cur->val != data) {
                data = cur->val;
                node->next = cur;
                node = node->next;
            }

            cur = cur->next;
        }

        node->next = NULL;
        return nhead;
    }
};
