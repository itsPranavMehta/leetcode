class Solution {
private:
    bool makeSquareHelper(vector<int>& sides,int a,vector<int>& matchsticks,int idx){
        
        for(auto& i:sides)  if(i>a) return 0;
        if(idx==matchsticks.size()) return 1;
        
        
        sides[0]+=matchsticks[idx];
        if(makeSquareHelper(sides,a,matchsticks,idx+1)) return 1;
        sides[0]-=matchsticks[idx];
        
        sides[1]+=matchsticks[idx];
        if(makeSquareHelper(sides,a,matchsticks,idx+1)) return 1;
        sides[1]-=matchsticks[idx];
        
        sides[2]+=matchsticks[idx];
        if(makeSquareHelper(sides,a,matchsticks,idx+1)) return 1;
        sides[2]-=matchsticks[idx];
        
        sides[3]+=matchsticks[idx];
        if(makeSquareHelper(sides,a,matchsticks,idx+1)) return 1;
        sides[3]-=matchsticks[idx];
        return 0;
        
    } 
public:
    bool makesquare(vector<int>& matchsticks) {
        int sz=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sz%4!=0) return 0;
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(matchsticks[0]>sz)   return 0;
        vector<int> sides(4,0);
        return makeSquareHelper(sides,sz/4,matchsticks,0);
        
    }
};