class Solution {
public:
    int minInsertions(string s) {
        // had to read the discuss section for this but was then able to understand
        // so in this question we use the longest common subsequence method and dp[i][j] represent i characters from the begining and j characters from the end
        // d[i][j] represent the number of same characters in the first i characters and last j characters (last j is starting from end), hence this would make a palindrome!
        int n=s.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i+1][j+1]=s[i]==s[n-j-1]?dp[i][j]+1:max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return n-dp[n][n];
        
    }
};