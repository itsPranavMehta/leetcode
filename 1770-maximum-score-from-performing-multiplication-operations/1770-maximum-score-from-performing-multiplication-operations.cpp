class Solution {
private:
    int util(vector<vector<int>>& dp,vector<int>& nums, vector<int>& multipliers,int n,int m,int i,int j){
        if(j==m)    return 0;
        if(dp[i][j]!=INT_MIN)    return dp[i][j];
        return dp[i][j]=max(util(dp,nums,multipliers,n,m,i+1,j+1)+multipliers[j]*nums[i],
                            util(dp,nums,multipliers,n,m,i,j+1)+multipliers[j]*nums[n-j+i-1]);
        
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(),m=multipliers.size();
        vector<vector<int>> dp(m,vector<int>(m,INT_MIN));
        return util(dp,nums,multipliers,n,m,0,0);
    }
};