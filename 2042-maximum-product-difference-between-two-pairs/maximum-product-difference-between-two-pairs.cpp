class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int biggest = 0;
        int secondbiggest = 0;
        int smallest = INT_MAX;
        int secondsmallest = INT_MAX;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > biggest){
                secondbiggest = biggest;
                biggest = nums[i];
            }
            else{
                secondbiggest = max(secondbiggest,nums[i]);
            }

            if(nums[i] < smallest){
                secondsmallest = smallest;
                smallest = nums[i];
            }
            else{
                secondsmallest = min(secondsmallest,nums[i]);
            }
        }

        return (biggest*secondbiggest)-(smallest*secondsmallest);
    }
};