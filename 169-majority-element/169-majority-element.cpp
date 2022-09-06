class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& i: nums)  mp[i]++;
        int occ=0,val=0;
        for(auto& [i,oc]:mp){
            if(oc>occ){
                occ=oc;
                val=i;
            }
        }
        return val;
    }
};