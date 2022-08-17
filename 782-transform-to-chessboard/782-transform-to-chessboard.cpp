class Solution {
public:
    private:
    int isRowSameOrInverted(vector<vector<int>> &board,int i,int j){
        int n=board.size();
        int same_count=0;
        for(int idx=0;idx<n;idx++){
            if(board[i][idx]==board[j][idx]){
                same_count++;
            }
        }
        return same_count==n?1:same_count==0?-1:0;   
    }
    int isColSameOrInverted(vector<vector<int>> &board,int i,int j){
        int n=board.size();
        int same_count=0;
        for(int idx=0;idx<n;idx++){
            if(board[idx][i]==board[idx][j]){
                same_count++;
            }
        }
        
        return same_count==n?1:same_count==0?-1:0;
    }
    
    bool possibleChessBoard(vector<vector<int>>& board){
        int n=board.size();
        int zeros=0,ones=0;
        for(auto& cell:board[0]){
            if(cell==0) zeros++;
            else ones++;
        }
        if(abs(zeros-ones)>1) return 0;
        zeros=0;
        ones=0;
        for(int r=0;r<n;r++){
            if(board[r][0]==0)  zeros++;
            else ones++;
        }
        if(abs(zeros-ones)>1) return 0;
        int cols_same=1,rows_same=1;
        for(int i=1;i<n;i++){
            int res1=isRowSameOrInverted(board,i,0);
            int res2=isColSameOrInverted(board,i,0);
            if(res1==0 || res2==0)  return 0;
            cols_same+=res2;
            rows_same+=res1;
        }
        return abs(rows_same)<=1 && abs(cols_same)<=1;
    }
    
    public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n=board.size();
        if(!possibleChessBoard(board))    return -1;
        
        int rows_change1=0; // rows change required keeping board[0][0] as 0;
        int cols_change1=0;
        
        for(int i=0;i<n;i++){
            if(board[i][0]!=i%2)    rows_change1++;
            if(board[0][i]!=i%2)    cols_change1++;
        }
        
        int rows_change2=n-rows_change1, cols_change2=n-cols_change1;
        int minSwaps=0;
        
        minSwaps+=rows_change1%2?rows_change2/2:(rows_change2%2?rows_change1/2:min(rows_change1/2,rows_change2/2));
        minSwaps+=cols_change1%2?cols_change2/2:(cols_change2%2?cols_change1/2:min(cols_change1/2,cols_change2/2));
                                               
        return minSwaps;
        
    }
};