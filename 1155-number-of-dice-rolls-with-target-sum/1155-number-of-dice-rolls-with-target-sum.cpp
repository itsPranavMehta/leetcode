class Solution {
public:
    int numRollsToTarget(int d, int f, int target) 
    {
        vector<vector<int>> dp(d+1,vector<int>(target+1));
        dp[0][0]=1;
        int m=1e9+7;
        for(int i=1;i<=d;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int v=1;v<=f;v++)
                {
                    if(v>j) break;

                    dp[i][j]+=dp[i-1][j-v];
                    dp[i][j]%=m;
                }
            }
        }
        return dp[d][target];
    }
};