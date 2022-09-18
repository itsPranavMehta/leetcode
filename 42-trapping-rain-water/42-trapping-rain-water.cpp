class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n,0),right(n,0);
        for(int i=0;i<n;i++){
            left[i]=i==0?0:left[i-1];
            left[i]=max(height[i],left[i]);
            right[n-i-1]=i==0?0:right[n-i];
            right[n-i-1]=max(height[n-i-1],right[n-i-1]);
        }
        int trappedWater=0;
        for(int i=0;i<n;i++){
            trappedWater+=min(right[i],left[i])-height[i];
        }
        return trappedWater;
        
    }
};