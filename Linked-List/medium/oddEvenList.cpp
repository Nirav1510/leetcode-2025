// https://leetcode.com/problems/odd-even-linked-list/


// odd even by index
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode *odd = head, *even = head->next;
    ListNode *evenStart = even;

    while(odd->next !=NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;

    return head;
}

// odd even by value
ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode *oddHead = new ListNode(-1);
    ListNode *odd = oddHead;
    ListNode *evenHead = new ListNode(-1);
    ListNode *even = evenHead;

    while(head){
        if(head->val%2){
            odd->next = head;
            odd = odd->next;
        }else{
            even->next = head;
            even = even->next;
        }
        head = head->next;
    }
    odd->next = evenHead->next;
    even->next = NULL;
    
    return oddHead->next;
}