class Solution {
    int bishopsAvailable(int i,int j,vector<vector<char>>& board){
        int numBishops=0;
        for(int r=i+1;r<8;r++){
            if(board[r][j]=='p')    numBishops++;
            if(board[r][j]!='.')   break;
        }
        for(int r=i-1;r>=0;r--){
            if(board[r][j]=='p')    numBishops++;
            if(board[r][j]!='.')   break;
        }
        for(int c=j+1;c<8;c++){
            if(board[i][c]=='p')    numBishops++;
            if(board[i][c]!='.')   break;
        }
        for(int c=j-1;c>=0;c--){
            if(board[i][c]=='p')    numBishops++;
            if(board[i][c]!='.')   break;
        }
        
        return numBishops;
    }
public:
    int numRookCaptures(vector<vector<char>>& board) {
        for(int r=0;r<8;r++){
            for(int c=0;c<8;c++){
                if(board[r][c]=='R'){
                    return bishopsAvailable(r,c,board);
                }
            }
        }
        return 0;
            
        
    }
};