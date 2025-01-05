// https://leetcode.com/problems/sort-list/

ListNode *findMiddle(ListNode *head){
    ListNode *slow = head, *fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode *merge(ListNode *a, ListNode *b){
    if(!a) return b;
    if(!b) return a;

    ListNode *result;

    if(a->val > b->val){
        result = b;
        result->next = merge(a, b->next);
    }else{
        result = a;
        result->next = merge(a->next, b);
    }
    return result;
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode *middle = findMiddle(head);
    ListNode *right = middle->next;
    middle->next = NULL;
    ListNode *left = head;

    left = sortList(left);
    right = sortList(right);

    return merge(left, right);
}