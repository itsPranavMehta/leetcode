class Solution {
private:
    bool poss(vector<int>& validNums,int n,int idx=0,int sum=0){
        if(idx==validNums.size() || sum==n)  return sum==n;
        if(sum+validNums[idx]>n)    return 0;
        return poss(validNums,n,idx+1,sum+validNums[idx]) || poss(validNums,n,idx+1,sum);
    }
public:
    bool checkPowersOfThree(int n) {
        vector<int> validNums;
        for(int i=0;pow(3,i)<=n;i++){
            validNums.push_back(pow(3,i));
        }
        return poss(validNums,n);
        
        
    }
};