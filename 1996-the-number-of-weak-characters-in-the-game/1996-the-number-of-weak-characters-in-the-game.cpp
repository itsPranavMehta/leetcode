class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        int ans=0;
        sort(properties.begin(),properties.end(),[](vector<int>& a,vector<int>& b)
             {
                 if(a[0]!=b[0])  return a[0]<b[0];
                 return a[1]>b[1];
             });
        int mx=-1;
        for(int i=properties.size()-1;i>=0;i--)
        {
            if(mx>properties[i][1]) ans++;
            mx=max(properties[i][1],mx);
        }
        return ans;
    }
};