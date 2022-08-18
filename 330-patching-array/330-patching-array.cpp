class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long missing=1;
        int added=0,idx=0;
        
        while(missing<=n){
        
            if(idx<nums.size() && nums[idx]<=missing){
                missing+=nums[idx++];
            }
            else{
                missing+=missing;
                added++;
            }
            
        }
        return added;
    }
};