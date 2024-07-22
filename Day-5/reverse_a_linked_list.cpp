class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        auto reverse = [&]() {
            ListNode *prev = NULL, *cur = head, *nxt;

            while (cur) {
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }

            return prev;
        };

        return reverse();
    }
};
