#include<bits/stdc++.h>
class Solution {
    map<int,char>mp;
    void init(){
        for(int i=0;i<26;i++){
            mp[i+1]='A'+i;
        }
    }
public:
    string convertToTitle(int n) {
        init();
        string ans="";
        while(n>0){
          int num=n%26;
          if(num == 0){
             ans='Z'+ans;
          }
          if(num>0 && num<=25){
            ans=mp[num]+ans;
          }
          n=(n-1)/26;
        }
        return ans;
    }
};