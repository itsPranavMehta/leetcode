class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n=machines.size();
        long sum=accumulate(machines.begin(),machines.end(),0ll);
        
        if(sum%n!=0){
            return -1;
        }
        
        int perMachine=sum/n;
        int moves= *max_element(machines.begin(),machines.end())-perMachine;
        long leftSum=machines[0];
        
        for(int i=1;i<n-1;i++){
            leftSum+=machines[i];
            int requiredOnLeft=perMachine*(i+1);
            moves=max(1l*moves,abs(requiredOnLeft-leftSum));
            
        }
        return moves;
        
    }
};
