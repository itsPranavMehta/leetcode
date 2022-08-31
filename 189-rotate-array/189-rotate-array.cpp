class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        vector<int> res(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            res[(k+i)%nums.size()]=nums[i];
        }
        nums.assign(res.begin(),res.end());
        
    }
};