class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        // so technically I've to consider the starting points as the first row and first column, and the next point in each of the iteration would be i+1,j+1;
        int n=mat.size(),m=mat[0].size();
        
        for(int startPoint=0;startPoint<n;startPoint++){
            vector<int> diag;
            
            for(int i=startPoint,j=0;i<n && j<m;i++,j++){
                diag.push_back(mat[i][j]);
            }
            
            sort(diag.begin(),diag.end());
            
            for(int i=startPoint,j=0;i<n && j<m;i++,j++){
                mat[i][j]=diag[j];
            }
        }
        for(int startPoint=1;startPoint<m;startPoint++){
            vector<int> diag;
            
            for(int j=startPoint,i=0;i<n && j<m;i++,j++){
                diag.push_back(mat[i][j]);
            }
            
            sort(diag.begin(),diag.end());
            
            for(int j=startPoint,i=0;i<n && j<m;i++,j++){
                mat[i][j]=diag[i];
            }
            
        }
        return mat;
        
        
    }
};