class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        
        int mx=*max_element(nums.begin(),nums.end());
        vector<bool> elements(mx+1,0);          // element lookup in o(1)
        for(auto& el:nums)  elements[el]=1;
        
        int numGcds=0;
        for(int num=1;num<=mx;num++)            // checking for all possible gcds
        {
            int g=0;
            for(int curr=num;curr<=mx;curr+=num){       // check for all elements that are a multiple of the current number
                if(elements[curr])    g=gcd(g,curr);
            }   
            if(g==num)  numGcds++;              // this gcd can be constructed!
        }
        return numGcds;
    }
};