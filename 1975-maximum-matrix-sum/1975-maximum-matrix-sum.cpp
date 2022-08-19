class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int numNegEl=0,min_el=INT_MAX;
        long sum=0;
        
        for(auto& row:matrix){
            for(auto& cell:row){
                sum+=abs(cell);
                min_el=min(min_el,abs(cell));
                if(cell<0)  numNegEl++;
            }
        }
        
        if(numNegEl%2)  sum-=2*min_el;
        return sum;
        
    }
};