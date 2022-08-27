class Solution {
public:
    int reinitializePermutation(int n) {
        //so the pattern is that till the element is present at a loc less than n/2 then it doubles in every iteration, after that it's pace of increasing slows down until it reaches the end then it starts decreasing rapidly and this decreases slowly lessens. so since 1 is the first element which changes position (0 doesn't move at all) hence it becomes easy to track just once as once it has completed it's trajectory (which is the biggest) all other elements have also completed the same!
        
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