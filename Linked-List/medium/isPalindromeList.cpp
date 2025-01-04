// https://leetcode.com/problems/palindrome-linked-list/

ListNode *reverseList(ListNode* head){
    ListNode *prev = NULL, *curr = head, *nextP;

    while(curr){
        nextP = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextP;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *secondHalf = reverseList(slow);
    ListNode *itr1 = head, *itr2 = secondHalf;

    while(itr2 && itr1){
        if(itr1->val != itr2->val){
            return false;
        }
        itr1 = itr1->next;
        itr2 = itr2->next;
    }

    return true;
}