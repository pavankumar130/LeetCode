class MyStack {
    queue<int>q1,q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        if(!q1.empty()){
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
        swap(q1,q2);
    }
    
    int pop() {
        int num= q1.front();
        q1.pop();
        return num;
    }
    
    int top() {
       return q1.front(); 
    }
    
    bool empty() {
        return q1.size()==0;
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