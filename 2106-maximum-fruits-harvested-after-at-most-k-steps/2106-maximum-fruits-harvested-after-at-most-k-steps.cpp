//okay so the solution would involve moving either of these 2 possibilites
// moving x steps to right and then k-2*x steps to left 
// moving x steps to left and then k-2*x steps to right
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        int LastPoint=fruits[n-1][0];
        
        vector<int> PreSum(LastPoint+1,0);
        for(auto& pos: fruits)  PreSum[pos[0]]=pos[1];
        for(int i=1;i<=LastPoint;i++)   PreSum[i]+=PreSum[i-1];
        
        int res=0;
        
        if(startPos>LastPoint){
            k-=(startPos-LastPoint);
            startPos=LastPoint;
        }
        
        for(int x=0;x<=k;x++){
            int stepsToLeft=x,StepsToRight=max(0,k-2*x);
            int left=startPos-stepsToLeft,right=min(LastPoint,startPos+StepsToRight);
            int CollectedFruits=(PreSum[startPos]-(left-1>=0?PreSum[left-1]:0))+(PreSum[right]-PreSum[startPos]);
            
            res=max(res,CollectedFruits);

            stepsToLeft=max(0,k-2*x),StepsToRight=x;
            left=startPos-stepsToLeft,right=min(LastPoint,startPos+StepsToRight);
            CollectedFruits=(PreSum[startPos]-(left-1>=0?PreSum[left-1]:0))+(PreSum[right]-PreSum[startPos]);
            
            res=max(res,CollectedFruits);           
        }
        return res;
    }
};