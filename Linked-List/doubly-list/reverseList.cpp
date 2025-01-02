// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

DLLNode* reverseDLL(DLLNode* head) {
    if(!head) return NULL;
    if(!head->next) return head;
    
    DLLNode *curr = head, *last = NULL;
    
    while(curr){
        last = curr->prev;
        
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev;
    }
    
    return last->prev;
}