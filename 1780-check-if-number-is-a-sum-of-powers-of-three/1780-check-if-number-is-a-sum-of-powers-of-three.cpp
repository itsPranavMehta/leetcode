class Solution {
public:
    bool checkPowersOfThree(int n,int p=0,int idx=0){
        while(n){
            if(n%3==2)  return 0;
            n=n%3==1?n-1:n/3;
        }
        return 1;
        
    }
};