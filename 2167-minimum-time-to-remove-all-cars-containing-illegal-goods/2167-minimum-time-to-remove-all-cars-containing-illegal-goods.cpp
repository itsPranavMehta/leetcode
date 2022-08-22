class Solution {
public:
    int minimumTime(string s) {
        int n=s.size();
        int dp[n];      // dp[i] represents minimum number of moves required to delete all 1s upto dp[i] without considering deletion from left;
        dp[0]=s[0]=='1'?1:0;
        int min_moves=n;
        for(int idx=1;idx<n;idx++){
            dp[idx]=min(dp[idx-1]+(s[idx]=='1')*2,idx+1);
            min_moves=min(min_moves,dp[idx-1]+n-idx);
        }
        min_moves=min(min_moves,dp[n-1]);
        return min_moves;
    }
};