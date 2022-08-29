class Solution {
private:
    bool validCoords(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n &&  j<m;
    }  
    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j, int n,int m){
        if(!grid1[i][j])    return 0;
        grid2[i][j]=0;
        int dirs[]={1,0,-1,0,1};
        bool validSubIsland=1;
        for(int idx=0;idx<4;idx++){
            int x=i+dirs[idx],y=j+dirs[idx+1];
            if(validCoords(x,y,n,m) && grid2[x][y]){
                if(!isSubIsland(grid1,grid2,x,y,n,m))   validSubIsland=false;
            }
        }
        return validSubIsland;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size(),subIsland=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    if(isSubIsland(grid1,grid2,i,j,n,m)) subIsland++;
                    
                }
            }
        }
        return subIsland;
    }
};