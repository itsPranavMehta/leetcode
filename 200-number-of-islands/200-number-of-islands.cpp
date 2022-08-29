class Solution {
private:
    bool validCoords(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    void visitIsland(vector<vector<char>>& grid,int i,int j){
        int n=grid.size(),m=grid[0].size();
        int dirs[]={1,0,-1,0,1};
        grid[i][j]='0';
        for(int dir=0;dir<4;dir++){
            int x=i+dirs[dir],y=j+dirs[dir+1];
            if(validCoords(x,y,n,m) && grid[x][y]=='1'){
                visitIsland(grid,x,y);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    num++;
                    visitIsland(grid,i,j);
                }
            }
        }
        return num;
    }
};