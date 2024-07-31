class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* small = dummy1;

        ListNode* dummy2 = new ListNode(0);
        ListNode* big = dummy2;

        ListNode* cur = head;

        while (cur) {
            ListNode* temp = cur->next;
            if (cur->val < x) {
                small->next = cur;
                small = small->next;
            } else {
                big->next = cur;
                big = big->next;
            }
            cur = temp;
        }
        big->next = NULL;
        small->next = dummy2->next;

        return dummy1->next;
    }
};
