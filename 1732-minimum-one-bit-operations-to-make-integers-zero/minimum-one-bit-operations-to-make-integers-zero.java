class Solution {
    public int minimumOneBitOperations(int n) {
        ArrayList<Long>f = new ArrayList<Long>(32);
        f.add(1L);
        for(int j = 1; j < 31; j++){
            f.add(f.get(j-1)*2 + 1);
        }

        int res=0;
        int plus=1;

        for(int j = 30; j>=0; j--){
            boolean isset = ((1<<j) & n) != 0;

            if(!isset){
                continue;
            }

            if(plus != 0){
                res+=f.get(j);
            }
            else{
                res-=f.get(j);
            }
            plus^=1;
        }

        return res;
    }
}