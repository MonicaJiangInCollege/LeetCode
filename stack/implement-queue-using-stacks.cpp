class MyQueue {
private:
    stack<int> input;   // 用于 push 操作
    stack<int> output;  // 用于 pop/peek 操作

    // 将 input 中的所有元素转移到 output 中，使得 output 的顶部为队列头部
    void transfer() {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if (output.empty()) {
            transfer();
        }
        int front = output.top();
        output.pop();
        return front;
    }
    
    int peek() {
        if (output.empty()) {
            transfer();
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */