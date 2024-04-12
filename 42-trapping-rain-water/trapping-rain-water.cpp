class Solution {
public:
vector<int> findright(vector<int>& height){
    int n=height.size();
    vector<int>arr(n);
    arr[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
       arr[i]=max(arr[i+1],height[i]);
    }
    return arr;
}
vector<int> findleft(vector<int>& height){
    int n=height.size();
    vector<int>arr(n);
    arr[0]=height[0];
    for(int i=1;i<n;i++){
       arr[i]=max(arr[i-1],height[i]);
    }
    return arr;
}
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left= findleft(height);
        vector<int>right= findright(height);

        int res=0;
        for(int i=1;i<n-1;i++){
            int val=min(left[i],right[i]);
            if(val > height[i]){
                res+=val-height[i];
            }
        }
        return res;
    }
};