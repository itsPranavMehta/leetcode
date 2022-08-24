class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);    //dp[i] represents the length of sequence possible with i as starting
        
        for(int i=0;i<n;i++){
            int j=nums[i],sz=1;
            while(j!=i && dp[j]==0) j=nums[j],sz++;
            if(j!=i){
                sz+=dp[j];
                j=i;
                while(dp[j]==0) dp[j]==sz--,j=nums[j];
            }
            else{
                dp[i]=sz;
                j=nums[i];
                while(i!=j){
                    dp[j]=sz;
                    j=nums[j];
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};