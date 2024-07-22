class Solution {
public:
    int getDecimalValue(ListNode* head) {
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
        head = reverse();

        int ans = 0;
        ListNode* cur = head;

        int i = 0;
        while (cur) {
            ans += (cur->val * pow(2, i++));
            cur = cur->next;
        }

        head = reverse();
        return ans;
    }
};
