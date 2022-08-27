class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // so in this question we use the knowledge of the standard ques- finding max sum of any formable rectange in a matrix.
        // we firstly select the leftmost column and keep it as the start column (we'll iterate this to check for all possibilities of the first leg of the triangle).. then in the inside loop we'll iterate from the start column to m. and for all rows we'll populate the sum matrix.this sum matrix(size=#row) would technically contain the sum of all columns till the column under cosideration.
        
        int n=matrix.size(),m=matrix[0].size(), res=INT_MIN;
        
        for(int startCol=0;startCol<m;startCol++){     // this is the starting col.
            vector<int> sums(n,0);
            for(int col=startCol;col<m;col++){        // column under consideration
                for(int row=0;row<n;row++){
                    sums[row]+=matrix[row][col];
                }
                
                set<int> sumsRecorded;
                sumsRecorded.insert(0);
                
                for(int row=0,currSum=0;row<n;row++){
                    
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