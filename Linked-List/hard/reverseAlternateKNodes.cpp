// https://www.interviewbit.com/problems/reverse-alternate-k-nodes/

Node* reverseAlternateKNodes(Node* head, int k){
	if(!head || !head->next || k==0) return head;

	// Node *check = head;
    // for(int i=0;i<k;i++){
	// 	if(!check){
	// 		return head;
	// 	}
	// 	check = check->next;
    // }

	Node* prev = NULL, *curr = head, *nextP;
	int count = 0;

	while(curr && count < k){
		nextP = curr->next;
		curr->next = prev;

		prev = curr;
		curr = nextP;
		count++;
	}

	if(head){
		head->next = curr;
	}

	count = 0;
    while (count < k - 1 && curr) {
        curr = curr->next;
        count++;
    }

	if(curr){
		curr->next = reverseAlternateKNodes(curr->next, k);
	}

	return prev;
}
