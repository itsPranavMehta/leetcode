class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        
        // so here we try to get the point where the maximum shifting would take place that is at what machine the number of clothes on left+ on current machine is most different than the number of clothes that optimally should've been there, these number of clothes would need to be transferred to the right and would hence require "number of clothes to be transferred time".
        
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
