class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        
        int mx=*max_element(nums.begin(),nums.end());
        vector<bool> elements(mx+1,0);
        for(auto& el:nums)  elements[el]=1;
        int numGcds=0;
        for(int num=1;num<=mx;num++)
        {
            int g=0;
            for(int curr=num;curr<=mx;curr+=num){
                if(elements[curr])    g=gcd(g,curr);
            }
            if(g==num)  numGcds++;
        }
        return numGcds;
    }
};