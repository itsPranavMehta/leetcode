class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> converted;
        
        for(int idx=0;idx<n;idx++){
            int num=nums[idx],v=0;
            string n=to_string(num);
        
            for(auto& c:n){
                v*=10;
                v+=mapping[c-'0'];
            }
            converted.push_back({v,idx});
        }
        
        sort(converted.begin(),converted.end());
        vector<int> res(n,0);
        
        for(int idx=0;idx<converted.size();idx++){
            res[idx]=nums[converted[idx].second];
        }
        
        return res;
        
    }
};