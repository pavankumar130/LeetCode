class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int cnt = 0;

        for(auto it:mp){
            // if(it.second == 2 || it.second == 3){
            //     cnt++;
            // }
            // else if(it.second >= 4){
            //     int num = it.second;
            //     int count = 0;
            //     if( ((int)num/3)%2 == 0 ){
            //         count += (num/3);
            //         count += (num/2);
            //     }
            //     else if(num%2 == 0){
            //         count = (num/2);
            //     }
            //     else{
            //         return -1;
            //     }
            //     cnt += count;
            // }
            
            // if(it.second == 1){
            //     return -1;
            // }

            int freq = (it.second);

            if(freq == 1)return -1;

            if(freq == 2|| freq == 3){
                cnt++;
            }else{
                int div = (freq / 3);
                int diff = freq - 3*div;

                if(diff & 1)
                {
                    diff += 3;
                    cnt += (div-1) + (diff/2);
                }
                else
                {
                    cnt += div + (diff/2);
                }
            }
        }
        return cnt;
    }
};