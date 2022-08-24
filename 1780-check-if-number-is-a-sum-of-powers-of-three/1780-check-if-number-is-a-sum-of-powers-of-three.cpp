class Solution {
public:
    bool checkPowersOfThree(int n,int p=0,int idx=0){
        if(n<=p || p+pow(3,idx)>n)    return n==p;
        return checkPowersOfThree(n,p+pow(3,idx),idx+1)    || checkPowersOfThree(n,p,idx+1);
        
        
    }
};