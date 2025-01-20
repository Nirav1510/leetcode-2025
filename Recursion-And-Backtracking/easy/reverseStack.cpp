// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

void insertAtBottom(stack<int> &s, int temp){
    if(s.size() == 0){
        s.push(temp);
    }else{
        int x = s.top();
        s.pop();
        insertAtBottom(s, temp);
        s.push(x);
    }
}

void Reverse(stack<int> &s){
    if (!s.empty()) {
        int temp = s.top(); 
        s.pop();
        Reverse(s);        
        insertAtBottom(s, temp);
    }
}