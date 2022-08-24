class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<bool> validCols(mat[0].size(),0);
        for(int i=0;i<mat[0].size();i++){
            int count=0;
            for(int j=0;j<mat.size();j++){
                if(mat[j][i])   count++;
            }
            if(count==1)    validCols[i]=1;
        }
        int res=0;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]){
                    if(!validCols[j]){
                        count=0;
                        break;
                    }
                    count++;
                }
            }
            if(count==1)    res++;    
        }
        return res;
        
    }
};