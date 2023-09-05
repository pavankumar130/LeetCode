class MinStack {
    stack<long long>st;
    long long int mini=(long long)LLONG_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty() && mini > val){
            long long int num=((long long)2*val- mini);
            st.push(num);
            mini=val;
        }
        else{
            if(st.empty()){
                mini=val;
            }
            st.push(val);
        }
    }
    
    void pop() {
        if(mini > st.top()){
            long long int num=mini;
            mini=((long long)2*num - st.top());
            st.pop();
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        if(mini > st.top()){
            return (int)mini;
        }
        else{
            return (int)st.top();
        }
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */