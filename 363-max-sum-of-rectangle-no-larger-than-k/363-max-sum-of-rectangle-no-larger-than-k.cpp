class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        int res=INT_MIN;
        for(int startCol=0;startCol<m;startCol++){     // this is the starting col.
            vector<int> sums(n,0);
            for(int col=startCol;col<m;col++){        // column under consideration
                for(int row=0;row<n;row++){
                    sums[row]+=matrix[row][col];
                }
                set<int> sumsRecorded;
                sumsRecorded.insert(0);
                int currSum=0;
                for(int row=0;row<n;row++){
                    
                    currSum+=sums[row];
                    auto it=sumsRecorded.lower_bound(currSum-k);
                    
                    if(it!=sumsRecorded.end()){
                        res=max(res,currSum-*it);
                    }
                    sumsRecorded.insert(currSum);
                }
                
            }
            
        }
        return res;
        
    }
};