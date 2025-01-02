// https://www.interviewbit.com/problems/kth-node-from-middle/

int kthNodeFromMiddleToLeft(ListNode* head, int k) {
    if (!head) return -1; 

    int length = 0;
    ListNode* temp = head;
    while (temp) {
        length++;
        temp = temp->next;
    }

    int mid = (length / 2) + 1;

    int target = mid - k;
    if (target <= 0) return -1; 

    temp = head;
    while (--target > 0 && temp) {
        temp = temp->next;
    }

    return temp ? temp->val : -1;
}
