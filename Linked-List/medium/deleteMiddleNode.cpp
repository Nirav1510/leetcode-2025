// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

ListNode* deleteMiddle(ListNode* head) {
    if(!head || !head->next) return NULL;

    ListNode *slow = head, *fast = head;
    fast = fast->next->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *toDelete = slow->next;
    slow->next = slow->next->next;
    delete(toDelete);

    return head;
}