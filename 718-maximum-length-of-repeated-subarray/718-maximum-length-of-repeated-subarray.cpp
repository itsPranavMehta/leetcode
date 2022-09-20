class Solution {
public:
    int memo[1001][1001];
    bool possible(vector<int>& nums1, vector<int>& nums2,int sz)
    {
        int n=nums1.size(),m=nums2.size();
        bool valid=true;
        for(int i=0;i<=n-sz;i++)
        {
            for(int j=0;j<=m-sz;j++)
            {
                valid=true;      
                int k=memo[i][j];
                for(;k<sz;k++)
                {
                    if(nums1[i+k]!=nums2[j+k])
                    {
                        memo[i][j]=k;
                        valid=false;
                        break;
                    }
                }
                if(valid)
                    return true;
            }
        }
        return false;
        
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        memset(memo,0,sizeof memo);   
        int n=nums1.size(),m=nums2.size(), low=0,high=min(n,m),ans=0;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(possible(nums1,nums2,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};