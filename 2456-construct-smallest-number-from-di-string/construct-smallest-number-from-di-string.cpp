class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.length();

        vector<int>arr;
        for(int i=1; i<=n+1; i++){
            arr.push_back(i);
        }

        for(int i=0; i<n ; i++){
            int temp=i;
            while(temp < n && pattern[temp] == 'D'){
                temp++;
            }

            reverse(arr.begin()+i, arr.begin()+temp+1);

            if(temp != i){
                i=temp-1;
            }
        }

        string res;
        for(int i=0; i<=n ;i++){
            res.push_back(arr[i]+'0');
        }
      return res;
    }
};