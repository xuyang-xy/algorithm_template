class MyStack {
private:
    queue<int> Q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        while (!Q.empty()) Q.pop();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q.push(x);
        int len = Q.size();
        for (int i = 0; i < len - 1; i++) {
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = Q.front();
        Q.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */