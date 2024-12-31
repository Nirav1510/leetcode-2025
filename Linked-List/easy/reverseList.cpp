// https://leetcode.com/problems/reverse-linked-list/

ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *nextP;

    while(curr){
        nextP = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextP;
    }
    return prev;
}

ListNode* reverseListRecursive(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode *newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}