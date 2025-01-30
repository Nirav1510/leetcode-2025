// https://leetcode.com/problems/merge-k-sorted-lists/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

ListNode* divideAndConquer(vector<ListNode*>& lists, int left, int right) {
    if (left == right) return lists[left];

    int mid = left + (right - left) / 2;
    ListNode* l1 = divideAndConquer(lists, left, mid);
    ListNode* l2 = divideAndConquer(lists, mid + 1, right);
    return mergeTwoLists(l1, l2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;
    return divideAndConquer(lists, 0, lists.size() - 1);
}

// ------- Using Min Heap -------
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min heap: smallest value at the top
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;

    for (ListNode* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (!minHeap.empty()) {
        ListNode* node = minHeap.top(); 
        minHeap.pop();
        
        tail->next = node; 
        tail = tail->next;  
        
        if (node->next) {
            minHeap.push(node->next); 
        }
    }

    return dummy->next;
}