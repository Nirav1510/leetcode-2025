// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

Node* reverse(Node* head) {
    Node* curr = head, *prev = NULL, *nextP;
    
    while (curr) {
        nextP = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextP;
    }
    
    return prev;
}

Node* addOne(Node* head) {
    if (!head) return new Node(1); 
    
    head = reverse(head);
    
    Node* curr = head;
    int carry = 1; 
    
    while (curr && carry) {
        int sum = curr->val + carry;
        curr->val = sum % 10; 
        carry = sum / 10;     
        
        if (!curr->next && carry) { 
            curr->next = new Node(carry);
            carry = 0; 
        }
        
        curr = curr->next; 
    }
    
    return reverse(head); 
}
