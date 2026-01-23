class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<long long>a(n);
        for(int i = 0; i < n; i++){
            a[i] = nums[i];
        }

        set<pair<long long, int>>st;
        vector<int>prev(n);
        vector<int>next(n);

        for(int i = 0; i < n; i++){
            prev[i] = i - 1;
            next[i] = i + 1;
        }

        int ans = 0;
        int cnt = 0;

        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1]){
                cnt++;
            }

            st.insert({a[i] + a[i + 1], i});
        }

        while(cnt > 0){
            int curr_ind = st.begin()->second;
            int next_ind = next[curr_ind];
            int prev_ind = prev[curr_ind];
            int next_next_ind = next[next_ind];

            // checking if curr pair is bad pair or not
            if(a[curr_ind] > a[next_ind]){
                cnt--;
            }

            // checking for bad_pair with next and prev value pair's
            if(prev_ind >= 0){
                if(a[prev_ind] > a[curr_ind] && a[prev_ind] <= a[curr_ind] + a[next_ind]){
                    cnt--;
                }
                else if(a[prev_ind] <= a[curr_ind] && a[prev_ind] > a[curr_ind] + a[next_ind]){
                    cnt++;
                }
            }

            if(next_next_ind < n){
                if(a[next_next_ind] >= a[next_ind] && a[next_next_ind] < a[curr_ind] + a[next_ind]){
                    cnt++;
                }
                else if(a[next_next_ind] < a[next_ind] && a[next_next_ind] >= a[curr_ind] + a[next_ind]){
                    cnt--;
                }
            }

            st.erase(st.begin());
            // updating pair sum value's

            if(prev_ind >= 0){
                st.erase({a[curr_ind] + a[prev_ind], prev_ind});
                st.insert({a[curr_ind] + a[prev_ind] + a[next_ind], prev_ind});
            }

            if(next_next_ind < n){
                st.erase({a[next_next_ind] + a[next_ind], next_ind});
                st.insert({a[curr_ind] + a[next_ind] + a[next_next_ind], curr_ind});
                prev[next_next_ind] = curr_ind;
            }

            // updating next, a value's 
            next[curr_ind] = next_next_ind;
            a[curr_ind] = a[curr_ind] + a[next_ind];
            ans++;
        }

        return ans;
    }
};