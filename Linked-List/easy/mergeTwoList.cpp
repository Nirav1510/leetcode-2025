// https://leetcode.com/problems/merge-two-sorted-lists/

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if(!a) return b;
    if(!b) return a;
    
    ListNode *result;
    
    if(a->val > b->val){
        result = b;
        result->next = mergeTwoLists(a, b->next);
    }else{
        result = a;
        result->next = mergeTwoLists(a->next, b);
    }
    
    return result;
}