class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        vector<int> dp={0,0,0};
        for(auto& num:nums){
            dp[num]+=(dp[num]+(num>0?dp[num-1]:1))%1000000007;
            dp[num]%=1000000007;
        }
        return dp[2];
        
    }
};