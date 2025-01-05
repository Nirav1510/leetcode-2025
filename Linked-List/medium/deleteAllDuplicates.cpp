// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

ListNode* deleteDuplicates(ListNode* head) {
    if(!head || !head->next) return head;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *prev = dummy, *curr = head;

    while(curr){
        while(curr->next && prev->next->val == curr->next->val){
            curr = curr->next;
        }

        if(prev->next == curr){
            prev = prev->next;
        }else{
            prev->next = curr->next;
        }

        curr = curr->next;
    }
    return dummy->next;
}