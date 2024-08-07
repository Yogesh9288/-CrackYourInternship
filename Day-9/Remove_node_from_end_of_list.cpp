class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=1;i<=n;i++)
        {
            fast=fast->next;
        }

        if(fast==NULL)
            return head->next;

        while(fast->next!=NULL&&fast)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
