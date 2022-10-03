class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, minTime = neededTime[0];
        for (int i = 0; i < colors.length() - 1; i++) {
            // IF ADJACENT COLORS ARE SAME
            if(colors[i]==colors[i+1]){
                // REMOVE THE BALLON WHICH REQUIRES MINIMUM TIME
                ans += min(minTime,neededTime[i+1]);
				// UPDATING THE MINIMUM TIME REQUIRED TO COMPARE IT WITH NEXT COLOR
                minTime = max(minTime,neededTime[i+1]);
            }
            else{
                minTime = neededTime[i+1];
            }
        }
        return ans;
    }
};