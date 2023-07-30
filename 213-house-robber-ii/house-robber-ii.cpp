class Solution {
public:
int help(vector<int>&temp){
    int n=temp.size();
    int prev=temp[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int p=temp[i];
        if(i>1){
            p+=prev2;
        }

        int np=prev;

        prev2=prev;
        prev= max(p,np);
    }
    return prev;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        vector<int>t1,t2;
        for(int i=0;i<n;i++){
         if(i != 0){
             t1.push_back(nums[i]);
         }
         if(i != n-1){
             t2.push_back(nums[i]);
         }
        }
        return max(help(t1), help(t2));
    }
};