class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> performance;
        for(int i=0;i<n;i++)    performance.push_back({efficiency[i],speed[i]});
        sort(performance.rbegin(),performance.rend());
        
        long res=0,currentSum=0;
        multiset<int> team;
        for(auto& [p,s]:performance){
            if(team.size()==k){
                currentSum-=*team.begin();
                team.erase(team.begin());
            }
            currentSum+=s;
            team.insert(s);
            res=max(res,currentSum*p);
        }
        return (int)(res%1000000007);
        
    }
};