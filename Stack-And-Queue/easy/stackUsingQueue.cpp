// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int> q ;
    MyStack() {}
    
    void push(int x) {
        int n = q.size();
        q.push(x);

        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if (q.empty()) {
            throw runtime_error("Stack is empty");
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        if (q.empty()) {
            throw runtime_error("Stack is empty");
        }
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};