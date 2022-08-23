class Solution {
private:
    bool poss(long m,vector<int>& nums,long k){
        for(auto& num:nums){
            k-=max(0ll,m-1ll*num);
        }
        return k>=0;
    }
public:
    int maximumProduct(vector<int>& nums, int k) {
        // so we should try to increase the smallest values
        int l=0,r=k+nums[0]+1,best_val=0,mod=1e9+7;    //let's determine what's the largest min value we can have
        sort(nums.begin(),nums.end());
        while(l<=r){
            int m=(l+r+1)>>1;
            if(poss(m,nums,k)){
                best_val=m;
                l=m+1;
            }
            else    r=m-1;
        }
        for(auto& num:nums){
            k-=max(0,best_val-num);
            num=max(num,best_val);
        }
        for(auto& num:nums){
            if(k>0){
                num++;
                k--;
            }
        }
        unsigned long ans=1;
        for(auto& num:nums){
            ans=1ll*num*ans;
            ans%=mod;
        }
        return ans;
    }
};