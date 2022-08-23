class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ops=0;
        while(target>1){
            if(!(target&1) && maxDoubles){
                target/=2;
                maxDoubles--;
                ops++;
            }
            else if(maxDoubles==0){
                ops+=target-1;
                target=1;
                
            }
            else{
                target--;
                ops++;
            }
        }
        return ops;
        
    }
};