class StockSpanner {
    stack<pair<int,int>>st;
    int count=0;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price){
            // cout<<st.top().first<<st.top().second<<endl;
            st.pop();
        }
        int ans;
        if(!st.empty()){
            ans=(count- st.top().second);
            // cout<<st.top().second<<endl;
        }
        else{
            ans= count+1;
        }
        st.push({price,count});
        count++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */