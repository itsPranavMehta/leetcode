class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        
        long sum=0, total=accumulate(nums.begin(),nums.end(),0ll),min_diff=LLONG_MAX;
        int res=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            sum+=1ll*nums[i];
            long diff=abs(sum/(i+1)-(n-i-1==0?0:(total-sum)/(n-i-1)));
            if(diff<min_diff)   res=i,min_diff=diff;
        }
        return res;
    }
};