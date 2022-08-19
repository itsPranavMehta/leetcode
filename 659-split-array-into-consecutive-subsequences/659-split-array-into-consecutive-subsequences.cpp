class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if(nums.size()<3)   return 0;
        unordered_map<int,int> start,end;
        for(auto& el:nums)  start[el]++;
        for(auto& el:nums){
            if(start[el]!=0){
                start[el]--;
                if(end[el-1]>0){
                    end[el-1]--;
                    end[el]++;
                }
                else if(start[el+1]>0 && start[el+2]>0){
                    start[el+1]--;
                    start[el+2]--;
                    end[el+2]++;
                }
                else    return 0;
            }
        }
        return 1;
        
    }
};