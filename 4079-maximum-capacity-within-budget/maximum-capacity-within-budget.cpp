class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>>arr(n);

        for(int i = 0; i < n; i++){
            arr[i] = {costs[i], capacity[i]};
        }

        sort(arr.begin(), arr.end());

        vector<int>prefix(n);
        prefix[0] = arr[0].second;
        for(int i = 1; i < n; i++){
            prefix[i] = max(prefix[i - 1], arr[i].second);
        }

        int maxi = 0;

        for(int i = 0; i < n; i++){
            int curr_cost = arr[i].first;
            int curr_cap = arr[i].second;

            if(curr_cost < budget){
                maxi = max(maxi, curr_cap);
            }
            else{
                break;
            }

            int target = budget - curr_cost;
            int low = 0;
            int high = i - 1;
            int ind = -1;

            while(low <= high){
                int mid = (low + high) / 2;
                if(arr[mid].first < target){
                    ind = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }

            if(ind != -1){
                maxi = max(maxi, curr_cap + prefix[ind]);
            }

        }

        return maxi;
    }
};