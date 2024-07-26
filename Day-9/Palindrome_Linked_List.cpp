class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == NULL)
            return true;
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

        ListNode *slow = head, *fast = head, *prev;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* mid = reverse(slow);
        slow = head;
        fast = mid;
        int flag = 1;
        while (slow && fast) {
            if (slow->val != fast->val) {
                flag = 0;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }

        mid = reverse(mid);
        prev->next = mid;

        return flag == 1;
    }
};
