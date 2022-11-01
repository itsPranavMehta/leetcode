class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> left(n,vector<int>(m,0)), up(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0,score=0;j<m;j++){
                if(grid[i][j]==0)   score=0;
                else score++;
                left[i][j]=score;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0,score=0;j<n;j++){
                if(grid[j][i]==0)   score=0;
                else score++;
                up[j][i]=score;
            }
        }
        
        int best=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int maxPossible=min(left[i][j],up[i][j]);
                for(int dis=maxPossible-1;dis>=0;dis--){    // -1 because self is included.         
                    int x=i-dis,y=j-dis;
                    int currMax=min(left[x][j],up[i][y]);   
                    
                    if(currMax>dis){                        // only then a square can be formed.
                        best=max(best,(dis+1)*(dis+1));     // dis represent the distance of the point under consideration from (i,j) since both the point under consideration and i,j are to be used for the square hence the area is (dis+1)*(dis+1)
                    }
                    
                }
            }
        }
        
        return best;
    }
};