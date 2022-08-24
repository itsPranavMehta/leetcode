class Solution {
public:
    bool checkPowersOfThree(int n,int p=0,int idx=0){
        // the ternary representation can contain 0-> this power not included, 1-> this power included,but can't contain, 2->this power included 2 times.
        while(n){
            if(n%3==2)  return 0;
            n=n%3==1?n-1:n/3;
        }
        return 1;
        
    }
};