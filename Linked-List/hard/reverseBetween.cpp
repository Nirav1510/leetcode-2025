// https://leetcode.com/problems/reverse-linked-list-ii/

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(!head || left == right || !head->next) return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* temp = dummy;

    for(int i=1;i<left;i++){
        temp = temp->next;
    }

    ListNode *prev = NULL, *curr = temp->next, *next;

    for(int i=0;i<=right-left;i++){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    temp->next->next = curr;
    temp->next = prev;

    return dummy->next;
}