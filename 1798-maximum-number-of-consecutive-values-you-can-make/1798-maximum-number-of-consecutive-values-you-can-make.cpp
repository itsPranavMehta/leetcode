class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int missing=1;
        sort(coins.begin(),coins.end());
        for(int idx=0;idx<coins.size();idx++){
            if(coins[idx]>missing){
                return missing;
            }
            missing+=coins[idx];
        }
        return missing;
        
    }
};