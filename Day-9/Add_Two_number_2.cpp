class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto reverse = [&](ListNode* head) {
            ListNode *cur = head, *nxt, *prev = NULL;
            while (cur) {
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }

            return prev;
        };

        l1 = reverse(l1);
        l2 = reverse(l2);
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        ListNode *cur1 = l1, *cur2 = l2;

        while (cur1 != NULL || cur2 != NULL || carry != 0) {
            int a = 0, b = 0;
            if (cur1 != NULL) {
                a = cur1->val;
                cur1 = cur1->next;
            }

            if (cur2 != NULL) {
                b = cur2->val;
                cur2 = cur2->next;
            }

            int sum = a + b + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur->next = new ListNode(sum);
            cur = cur->next;
        }

        l1 = reverse(l1);
        l2 = reverse(l2);
        dummy->next = reverse(dummy->next);
        return dummy->next;
    }
};
