// https://leetcode.com/problems/add-two-numbers/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    if(!l2) return l1;

    ListNode *sumList = new ListNode(-1);
    ListNode *curr = sumList, *itr1 = l1, *itr2 = l2;
    int carry = 0;

    while(itr1 || itr2 || carry){
        int sum = carry;

        if(itr1){
            sum+= itr1->val;
            itr1 = itr1->next;
        }

        if(itr2){
            sum+= itr2->val;
            itr2 = itr2->next;
        }

        int lastDigit = sum%10;
        carry = sum/10;

        curr->next = new ListNode(lastDigit);
        curr = curr->next;
    }

    return sumList->next;
}