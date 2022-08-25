class Solution {
private:
    int construct(vector<vector<int>>& mp,string& target,int idx, int used, int dp[1001][1001],int n){
        if(idx==target.size())  return 1;
        if(dp[idx][used]!=-1)   return dp[idx][used];
        
        int ways=0,mod=1e9+7;
        
        for(int i=used;i<n-(target.size()-idx-1);i++){
            if(mp[i][target[idx]-'a']!=0){
                ways+=(1ll*mp[i][target[idx]-'a']*construct(mp,target,idx+1,i+1,dp,n))%mod;
                ways%=mod;
            }
        }
                
        return dp[idx][used]=ways;
        
    }
public:
    int numWays(vector<string>& words, string target) {
        int n=words[0].size(),sz=target.size();
        vector<vector<int>> mp(n,vector<int>(26,0));       //chars and corresponding locs;
        int mx_size=0;
        for(auto& word:words){
            for(int idx=0;idx<word.size();idx++){
                mp[idx][word[idx]-'a']++;
            }
        }
        int dp[1001][1001];
        memset(dp,-1,sizeof dp);
        return construct(mp,target,0,0,dp,n);
        
    }
};