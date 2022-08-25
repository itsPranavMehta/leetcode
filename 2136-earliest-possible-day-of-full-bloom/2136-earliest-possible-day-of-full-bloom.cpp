class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        // so t
        int n=plantTime.size();
        vector<pair<int,int>> time;
        for(int i=0;i<n;i++){
            time.push_back({growTime[i],plantTime[i]});
        }
        sort(time.begin(),time.end());
        int t=0;
        for(auto &[g,p]:time){
            t=max(t,g)+p;
        }
        return t;
    }
};