class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int res=0;
        for(int x=startPos[0];x!=homePos[0];){
            if(x<homePos[0])    x++;
            else x--;
            res+=rowCosts[x];
        }
        for(int y=startPos[1];y!=homePos[1];){
            if(y<homePos[1])    y++;
            else y--;
            res+=colCosts[y];
        }
        return res;
        
    }
};