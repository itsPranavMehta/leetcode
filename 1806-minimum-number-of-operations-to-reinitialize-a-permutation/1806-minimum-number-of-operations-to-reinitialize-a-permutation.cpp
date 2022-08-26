class Solution {
public:
    int reinitializePermutation(int n) {
        int ops=0,idx=1;
        while(ops==0 || idx>1){
            if(idx<n/2){
                idx*=2;
            }
            else idx=2*idx-n+1;
            ops++;
        }
        return ops;
        
    }
};