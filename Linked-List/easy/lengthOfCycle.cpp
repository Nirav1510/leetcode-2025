// https://practice.geeksforgeeks.org/problems/length-of-loop/1

int countNodesInLoop(Node *head) {
    Node *slow = head, *fast = head;
    
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            int length = 1;
            fast = fast->next;
    
            while(slow!=fast){
                length++;
                fast = fast->next;
            }
            
            return length;
        }
    }
    
    return 0;
}