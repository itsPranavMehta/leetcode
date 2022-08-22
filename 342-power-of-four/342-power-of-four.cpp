class Solution {
public:
    bool isPowerOfFour(int n) {
        // so just 1 bit set in binary makes it a power of 2
        // 0001 , 0100 , 10000, so basically bit set at odd index makes it a power of 4;
        if(n<0) return 0;
        int count=0;
        while(n){
            count++;
            if(n%2 && n/2)  return 0; 
            n/=2;
        }
        return count%2;
        
    }
};