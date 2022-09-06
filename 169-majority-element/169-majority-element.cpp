class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=nums[0],occ=1;
        for(int i=1;i<nums.size();i++){
            if(val!=nums[i]){
                if(occ) occ--;
                else {
                    occ=1;
                    val=nums[i];
                }
            }
            else{
                occ++;
            }
        }
        return val;
        
    }
};