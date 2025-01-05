// https://leetcode.com/problems/reverse-nodes-in-k-group/

ListNode* reverseInKPairs(ListNode* head, int k) {
    if(!head || !head->next) return head;

    ListNode* temp = head;

    for(int i = 0; i < k; i++){
        if(!temp) return head;
        temp = temp->next;
    }

    ListNode *prev = NULL, *curr = head, *nextP;
    int count = 0;

    
    while(curr && count < k){
        nextP = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = nextP;
    }
    
    if(nextP){
        head->next = reverseInKPairs(nextP, k);
    }

    return prev;
}