// https://www.interviewbit.com/problems/even-reverse/

ListNode *reverse(ListNode *head){
    ListNode *prev = NULL, *curr = head, *nextP;
    
    while(curr){
        nextP = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = nextP;
    }
    return prev;
}
 
ListNode *evenIndexReverse(ListNode *head) {
    if(!head || !head->next) return head;
    
    ListNode *evenList = new ListNode(-1);
    ListNode *even = evenList, *curr = head;
    
    while (curr && curr->next) {
        even->next = curr->next;     
        even = even->next;    
              
        curr->next = curr->next->next; 
        curr = curr->next;
    }
    even->next = NULL;
    
    ListNode *evenReverse = reverse(evenList->next);
    delete evenList;
    
    curr = head, even = evenReverse;
    
    while(curr && even){
        ListNode *tempOdd = curr->next;  
        ListNode *tempEven = even->next;

        curr->next = even;  
        even->next = tempOdd; 

        curr = tempOdd;      
        even = tempEven;  
    }
    
    return head;
}