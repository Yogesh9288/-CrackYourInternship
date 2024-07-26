class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;

        ListNode cur1 = l1, cur2 = l2;

        while (cur1 != null || cur2 != null || carry != 0) {
            int a = 0, b = 0;
            if (cur1 != null) {
                a = cur1.val;
                cur1 = cur1.next;
            }

            if (cur2 != null) {
                b = cur2.val;
                cur2 = cur2.next;
            }

            int sum = a + b + carry;
            carry = sum / 10;
            sum = sum % 10;
            cur.next = new ListNode(sum);
            cur = cur.next;
        }

        return dummy.next;
    }
}
