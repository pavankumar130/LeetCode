#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree< int, null_type, greater_equal<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;
        ordered_set s1,s2;

        arr1.push_back(nums[0]);
        s1.insert(nums[0]);
        arr2.push_back(nums[1]);
        s2.insert(nums[1]);

        for(int i = 2; i < nums.size(); i++){
            int val = nums[i] ;
            int id1 = s1.order_of_key(val);
            int id2 = s2.order_of_key(val);

            if(id1 > id2){
                arr1.push_back(nums[i]);
                s1.insert(nums[i]);
            }
            else if(id1 < id2){
                arr2.push_back(nums[i]);
                s2.insert(nums[i]);
            }
            else if(id1 == id2){
                if(arr1.size() > arr2.size()){
                    arr2.push_back(nums[i]);
                    s2.insert(nums[i]);
                }
                else{
                    arr1.push_back(nums[i]);
                    s1.insert(nums[i]);
                }
            }
        }

        for(auto it:arr2){
            arr1.push_back(it);
        }

        return arr1;
    }
};