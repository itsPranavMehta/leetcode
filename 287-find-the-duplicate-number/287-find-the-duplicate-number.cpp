// Here we try to visit the entire array for every bit iteratively, for a single bit we check the number of bits that should've been set if there were no repititions -we can do this by using the index itself as index ranges from 0 to n-1. then we also calculate the number of bits which are actually set, if the number of actually set bits are greater than the expected then we are sure that the duplicate number has this bit set, hence we update our result accordingly,
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate=0;
        
        for(int bit=0;bit<32;bit++){
            
            int bitValue=1<<bit, actualBitSum=0,expectedBitSum=0;
            
            for(int idx=0;idx<nums.size();idx++){
                
                if(idx & bitValue)    expectedBitSum++;
                if(nums[idx] & bitValue)    actualBitSum++;
            }
        
            if(actualBitSum>expectedBitSum) duplicate+=bitValue;
        }
        
        return duplicate;
    }
};