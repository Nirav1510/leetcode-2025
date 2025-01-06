// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node *mergeList(Node *a, Node *b){
    if(!a) return b;
    if(!b) return a;
    
    Node *dummy = new Node(-1);
    Node *tail = dummy;
    
    while(a && b){
        if(a->data > b->data){
            tail->bottom = b;
            b = b->bottom;
        }else{
            tail->bottom = a;
            a = a->bottom;
        }
        
        tail = tail->bottom;
    }
    
    if(a){
        tail->bottom = a; 
    }else{
        tail->bottom = b;
    }
    return dummy->bottom;
}

Node *flatten(Node *root) {
    if(!root || !root->next){
        return root;
    }
    
    Node *curr = root;
    while (curr->next) {
        curr = curr->next;
        root = mergeList(root, curr);
    }
    
    return root;
}