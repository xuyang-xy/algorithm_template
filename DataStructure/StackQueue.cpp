class CQueue {
private:
    stack<int> stack_main, stack_aux;
public:
    CQueue() {
        while(!stack_main.empty()) stack_main.pop();
        while(!stack_aux.empty()) stack_aux.pop();
    }
    
    void appendTail(int value) {
        stack_main.push(value);
    }
    
    int deleteHead() {
        if (stack_aux.empty()) {
            while (!stack_main.empty()) {
                stack_aux.push(stack_main.top());
                stack_main.pop();
            }
        }
        if (stack_aux.empty()) return -1;
        else {
            int temp = stack_aux.top();
            stack_aux.pop();
            return temp;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */