// https://leetcode.com/problems/intersection-of-two-linked-lists/

int listLength(ListNode *head){
    ListNode* temp = head;
    int length = 0;

    while(temp){
        length++;
        temp = temp->next;
    }
    return length;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return NULL;

    int lA = listLength(headA), lB = listLength(headB);

    int diff = 0;
    ListNode *p1, *p2;

    if(lA>lB){
        diff = lA-lB;
        p1 = headA;
        p2 = headB;
    }else{
        diff = lB-lA;
        p1 = headB;
        p2 = headA;
    }

    while(diff--){
        p1 = p1->next;
        if(!p1){
            return NULL;
        }
    }

    while(p1 && p1){
        if(p1 == p2){
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

// optimal solution
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return NULL;

    ListNode *p1 = headA, *p2 = headB;

    while(p1 != p2){
        p1 = p1 ? p1->next : headB;
        p2 = p2 ? p2->next : headA;
    }

    return p1;
}