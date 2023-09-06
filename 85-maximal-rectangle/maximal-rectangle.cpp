class Solution {
public:
void findright(vector<int>&arr, vector<int>&right){
    int n=arr.size();
    stack<int>st;
    for(int i=n-1;i>=0;i--){
       while(!st.empty() && arr[st.top()]>=arr[i]){
		   st.pop();
	   }
	   if(!st.empty()){
		   right[i]=st.top()-1;
	   }
	   else{
		   right[i]=n-1;
	   }
	   st.push(i);
	}
}
void findleft(vector<int>&arr,vector<int>&left){
    int n=arr.size();
    stack<int>st;
	for(int i=0;i<n;i++){
       while(!st.empty() && arr[st.top()] >= arr[i]){
		   st.pop();
	   }
	   if(!st.empty()){
		   left[i]=st.top()+1;
	   }
	   else{
		   left[i]=0;
	   }
	   st.push(i);
	}
}
int solve(vector<int>&arr){
	int n=arr.size();
	vector<int>left(n,0);
	vector<int>right(n);
	findleft(arr,left);
	findright(arr,right);
	int res=0;
	for(int i=0;i<n;i++){
		int num =((right[i]-left[i]+1)*arr[i]);
		res=max(res,num);
	}
  return res;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int res=0;
        vector<int>arr(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    arr[j]++;
                }
                else{
                    arr[j]=0;
                }
            }
            int num=solve(arr);
            res=max(res,num);
        }
        return res;
    }
};