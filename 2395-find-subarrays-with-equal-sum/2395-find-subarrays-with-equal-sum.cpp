class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> sums;
        for(int i=0;i<nums.size()-1;i++){
            int sum=nums[i]+nums[i+1];
            if(sums.count(sum)) return 1;
            sums.insert(sum);
        }
        return 0;
    }
};