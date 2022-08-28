class Solution {
private:
    bool checkValidity(vector<vector<char>>& board,int i, int j, char c,int xdir, int ydir){
        int n=8;// hardcoded;
        i+=xdir;
        j+=ydir;
        if(i<0 || i>=n || j<0 || j>=n || board[i][j]!=(c=='W'?'B':'W'))  return 0;
        i+=xdir;
        j+=ydir;
        while(i<n && j<n && i>=0 && j>=0){
            if(board[i][j]==c)  return 1;
            if(board[i][j]=='.')    return 0;
            i+=xdir;
            j+=ydir;
        }
        return 0;
        
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        if(checkValidity(board,rMove,cMove,color,1,0))  return 1;
        if(checkValidity(board,rMove,cMove,color,0,1))  return 1;
        if(checkValidity(board,rMove,cMove,color,-1,0))  return 1;
        if(checkValidity(board,rMove,cMove,color,1,1))  return 1;
        if(checkValidity(board,rMove,cMove,color,-1,-1))  return 1;
        if(checkValidity(board,rMove,cMove,color,-1,1))  return 1;
        if(checkValidity(board,rMove,cMove,color,0,-1))  return 1;
        if(checkValidity(board,rMove,cMove,color,1,-1))  return 1;
        return 0;
        
        
    }
};