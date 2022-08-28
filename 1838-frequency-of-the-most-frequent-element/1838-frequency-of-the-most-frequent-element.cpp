class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size(),res=1;
        sort(nums.begin(),nums.end());
        int setSize=1;
        long movesUsed=0;
        for(int i=1;i<n;i++){
            movesUsed+=1ll*setSize*(nums[i]-nums[i-1]);
            while(movesUsed>k){
                int j=i-setSize;
                movesUsed-=(nums[i]-nums[j]);
                setSize--;
            }
            setSize++;
            res=max(res,setSize);
        }
        return res;
        
        
    }
};