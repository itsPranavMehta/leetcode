class Solution {
private:
    bool validCoords(int i,int j, int n){
        return i>=0 && j>=0 && i<n && j<n;
    }
    
    int calculateIslandSize(int i,int j,vector<vector<int>>& island,vector<vector<int>>& grid,int id){
        int dir[]={1,0,-1,0,1};
        int n=grid.size();
        int islands=1;      //current cell already added;
        island[i][j]=id;
        for(int idx=0;idx<4;idx++){
            int x=i+dir[idx],y=j+dir[idx+1];
            if(validCoords(x,y,n) && grid[x][y]!=0 && island[x][y]==-1){
                islands+=calculateIslandSize(x,y,island,grid,id);
            }
        }
        return islands;
    }
    
    int getNeighbours(int i,int j,vector<vector<int>>& islandId,unordered_map<int,int>& islandSize){
        int dir[]={1,0,-1,0,1};
        int n=islandId.size();
        unordered_set<int> neighbourChecked;
        int neighbours=0;
        for(int idx=0;idx<4;idx++){
            int x=i+dir[idx],y=j+dir[idx+1];
            if(validCoords(x,y,n) && islandId[x][y]!=-1 && !neighbourChecked.count(islandId[x][y])){
                neighbourChecked.insert(islandId[x][y]);
                neighbours+=islandSize[islandId[x][y]];
                
            }
        }
        return neighbours+1;    //  +1 for self
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> islandId(n,vector<int>(n,-1));//{number of cells in the island, id of island}
        unordered_map<int,int> islandSize;                 // map id to island size;
        int id=0,mx_size=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && islandId[i][j]==-1){
                    islandSize[id]=calculateIslandSize(i,j,islandId,grid,id);
                    mx_size=max(mx_size,islandSize[id]);
                    id++;
                }
            }
        }
        
        mx_size=min(mx_size+1,n*n);       // addition of single cell or all cells combined whichever is minimum
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){       
                if(grid[i][j]==0){
                    mx_size=max(mx_size,getNeighbours(i,j,islandId,islandSize));
                }
            }
        }
        return mx_size;
    }
};

// [0,0,0,0,0,0,0]
// [0,1,1,1,1,0,0]
// [0,1,0,0,1,0,0],
// [1,0,1,0,1,0,0],
// [0,1,0,0,1,0,0],
// [0,1,0,0,1,0,0],
// [0,1,1,1,1,0,0]]