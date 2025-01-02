// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

Node* deleteNode(Node* head, int k) {
    if (!head) return NULL;

    // If the position is 1, delete the head node
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
        return head;
    }
    
    int count = 1;
    Node *temp = head;
    
    while(temp && count < k){
        temp = temp->next;
        count++;
    }
    
    if(!temp) return head;
    
    if (temp->prev){ 
        temp->prev->next = temp->next;
    }

    if (temp->next){ 
        temp->next->prev = temp->prev;
    }

    delete temp;
    
    return head;
}