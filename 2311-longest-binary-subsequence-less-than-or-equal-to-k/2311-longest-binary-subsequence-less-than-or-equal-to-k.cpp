class Solution {
public:
    int longestSubsequence(string s, long k) {
        int i=s.size()-1;
        long sum=0,len=0;
        for(;i>=0;i--){
            if(s[i]=='0')   len++;
            else{
                if(len<32 && sum+pow(2,len)<=k){
                    sum+=pow(2,len);
                    len++;
                }
            }
        }
        return len;
        
    }
};