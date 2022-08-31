class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,n=g.size(),m=s.size(),ans=0;
        for(;i<n && j<m;){
            if(s[j]>=g[i]){
                i++;j++;
                ans++;
            }
            else{
                j++;
            }
        }
        return ans;
        
    }
};