// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Node* segregate(Node* head) {
    if (!head || !head->next) return head;

    Node zeroDummy(0), oneDummy(0), twoDummy(0);
    Node *zeroTail = &zeroDummy, *oneTail = &oneDummy, *twoTail = &twoDummy;

    Node* curr = head;
    while (curr) {
        if (curr->data == 0) {
            zeroTail->next = curr;
            zeroTail = zeroTail->next;
        } else if (curr->data == 1) {
            oneTail->next = curr;
            oneTail = oneTail->next;
        } else { 
            twoTail->next = curr;
            twoTail = twoTail->next;
        }
        curr = curr->next;
    }

    zeroTail->next = oneDummy.next ? oneDummy.next : twoDummy.next;
    oneTail->next = twoDummy.next;
    twoTail->next = NULL;

    return zeroDummy.next;
}