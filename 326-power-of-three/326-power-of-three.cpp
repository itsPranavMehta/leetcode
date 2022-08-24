class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n){
            if(n%3) return n==1;
            n/=3;
        }
        return 0;
        
    }
};