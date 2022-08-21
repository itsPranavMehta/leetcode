class Solution {
private:
    void solve(int idx,int numArrows,vector<int>& alice,vector<int>& bob,vector<int>& best,int& max_score,int score=0){
        if(idx==alice.size()){
            if(numArrows!=0)    bob[bob.size()-1]+=numArrows;
            if(score>max_score){
                best=bob;
                max_score=score;
            }
            bob[bob.size()-1]-=numArrows;
            return;
        }
        if(alice[idx]<numArrows){       // then only I can win this particular spot
            bob[idx]=alice[idx]+1;
            solve(idx+1,numArrows-1-alice[idx],alice,bob,best,max_score,score+idx);
            bob[idx]=0;
        }
        solve(idx+1,numArrows,alice,bob,best,max_score,score);
    }
    
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> res(aliceArrows.size(),0),bobArrows(aliceArrows.size(),0);
        int mx=0;
        solve(0,numArrows,aliceArrows,bobArrows,res,mx);
        return res;
        
    }
};