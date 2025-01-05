// https://leetcode.com/problems/rotate-list/

ListNode *rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    ListNode *curr = head;
    int length = 1;
    while (curr->next) {
        length++;
        curr = curr->next;
    }

    k = k % length;
    if (k == 0) return head;  

    ListNode *newTail = head;
    for (int i = 1; i < length - k; i++) {
        newTail = newTail->next;
    }
    ListNode *newHead = newTail->next;
    
    newTail->next = NULL;
    curr->next = head;

    return newHead;
}