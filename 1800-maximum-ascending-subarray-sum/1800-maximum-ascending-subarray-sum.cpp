class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum=nums[0],mxSum=nums[0];
        for(int idx=1;idx<nums.size();idx++){
            if(nums[idx-1]<nums[idx]){
                currSum+=nums[idx];
            }
            else{
                mxSum=max(mxSum,currSum);
                currSum=nums[idx];
            
            }
        }
        return max(mxSum,currSum);
        
    }
};