// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow = head, *fast = head;

    while(n-- && fast){
        fast = fast->next;
    }

    if (fast == NULL) return head->next;

    while(fast && fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete(toDelete);

    return head;
}