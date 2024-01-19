class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        long long start = 0, end = 1e18;
        long long ans = 0;

        while(start <= end){
            long long mid = (start+end)/2;
            long long cnt = 0;
            for(long long j = 0; j <= 60; j++){
                if( (j+1)%x == 0){
                    long long one = 1;
                    long long nn = (one<<(j+1));
                    long long pack = (mid+1)/nn;
                    cnt += (pack*(nn/2));
                    if(cnt >= 1e15){
                        break;
                    }
                    cnt += max((long long)0 ,((mid+1)%nn) - nn/2 );
                    if(cnt >= 1e15){
                        break;
                    }
                }
            }
            if(cnt <= k){
                start = mid+1;
                ans = max(ans,mid);
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};