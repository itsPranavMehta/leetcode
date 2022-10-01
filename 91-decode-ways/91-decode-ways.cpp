class Solution {
private:
    int dp[201];
    bool canBe2DigLetter(string& s,int i){
        return i<s.size()-1 && (s[i]=='1' || s[i]=='2'  && s[i+1]<='6');       // either starts with 1 or <=26
    }
public:
    int numDecodings(string s,int i=0) {
        if(i==0)    memset(dp,-1,sizeof dp);            //intialise the dp 
        
        if(i==s.size()) return 1;
        if(s[i]=='0')   return 0;
        
        if(dp[i]!=-1)   return dp[i];
        
        return dp[i]=numDecodings(s,i+1)+(canBe2DigLetter(s,i)?numDecodings(s,i+2):0);
    }
};