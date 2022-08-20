class Solution {
    private:
    
    // 0->  (0,-1)
    // 1->  (-1,0)
    // 2->  (1,0)
    // 3->  (0,1)
    int getDir(int dirx,int diry){
        if(dirx==-1)    return 0;
        if(diry==-1)    return 1;
        if(dirx==1)     return 2;
        return 3;
    }
    
    bool cellVisited(int i,int j,vector<vector<vector<bool>>>& traversed){
        return traversed[i][j][0] || traversed[i][j][1] ||traversed[i][j][2] ||traversed[i][j][3];
    }
    
    bool directionVisited(int i,int j,vector<vector<vector<bool>>>& traversed, int dirx,int diry){
        return traversed[i][j][getDir(dirx,diry)];
    }
    
    int visitCells(int dirx,int diry,int n,int m, int i,int j,vector<vector<vector<bool>>>& traversed){
        int unvisitedCells=0;
            
        while(i<n && j<m && i>=0 && j>=0 && !directionVisited(i,j,traversed,dirx,diry)){
            if(!cellVisited(i,j,traversed)) unvisitedCells++;
            traversed[i][j][getDir(dirx,diry)]=1;
            i+=dirx;
            j+=diry;
        }
        return unvisitedCells;
    }

public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<vector<bool>>> traversed(n,vector<vector<bool>>(m,vector<bool>(4,0)));
        for(auto& wall:walls){
            for(int dir=0;dir<4;dir++){
                traversed[wall[0]][wall[1]][dir]=1;
            }
        }
        int cellsGuarded=0;
        for(auto& guard:guards){
            int i=guard[0],j=guard[1];
            cellsGuarded+=visitCells(1,0,n,m,i+1,j,traversed);      // go down
            cellsGuarded+=visitCells(-1,0,n,m,i-1,j,traversed);     // go up
            cellsGuarded+=visitCells(0,1,n,m,i,j+1,traversed);      // go right
            cellsGuarded+=visitCells(0,-1,n,m,i,j-1,traversed);     // go left
            if(!traversed[i][j][0] && !traversed[i][j][1] && !traversed[i][j][2] && !traversed[i][j][3])    //if the guard pos hasn't been traversed by any other gaurds
                cellsGuarded++;
            
            for(int dir=0;dir<4;dir++)          //mark all directions as closed
                traversed[i][j][dir]=1;
            
        }
        return n*m-cellsGuarded-walls.size();
        
    }
};