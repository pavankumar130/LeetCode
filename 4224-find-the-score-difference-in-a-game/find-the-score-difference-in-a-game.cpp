class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();

        int player_0 = 0;
        int player_1 = 0;
        bool prev = false;
        int game = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2){
                prev = !prev;
            }
            if(game == 6){
                prev = !prev;
                game = 0;
            }

            if(prev){
                player_1 += nums[i];
            }
            else{
                player_0 += nums[i];
            }

            game++;
        }
        return (player_0 - player_1);
    }
};