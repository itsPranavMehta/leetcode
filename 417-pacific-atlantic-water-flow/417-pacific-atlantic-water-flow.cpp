class Solution {
private:
    bool validCoords(int i,int j,int n,int m){
        return i>=0 && i<n && j<m && j>=0;
    }

    void bfs(vector<vector<int>>& heights,vector<vector<bool>>& visited){
        int n=heights.size(),m=heights[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j])   q.push({i,j});
            }
        }
        int dirs[]={1,0,-1,0,1};
        while(q.size()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            for(int dir=0;dir<4;dir++){
                int x=i+dirs[dir],y=j+dirs[dir+1];
                if(validCoords(x,y,n,m) && !visited[x][y] && heights[x][y]>=heights[i][j]){
                    visited[x][y]=1;
                    q.push({x,y});
                }
            }
        }    
    }
    
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,0)),atlantic(n,vector<bool>(m,0));
        vector<vector<int>> res;
        fill(pacific[0].begin(),pacific[0].end(),1);      // 1st row can be accessed by the pacific ocean as a whole;
        for(int i=0;i<n;i++)    pacific[i][0]=1;     // 1st column can also be accessed by pacific ocean
        
        fill(atlantic[n-1].begin(),atlantic[n-1].end(),1);      //filling the cells for atlantic ocean reachable water in the same manner
        for(int i=0;i<n;i++)    atlantic[i][m-1]=1;
        
        bfs(heights,pacific);
        bfs(heights,atlantic);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j])   res.push_back({i,j});
            }
        }
        return res;
        
        
        
    }
};