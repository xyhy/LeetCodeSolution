class Solution {
public:
    int vis[201][201]={0};
    void solve(vector<vector<char>>& board) {
        for (int i=0; i<board[0].size(); i++){     // first row
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0, i, board);
            }
        }
        for (int i=0; i<board[0].size(); i++){     // last row
            if(!vis[board.size()-1][i] && board[board.size()-1][i]=='O'){
                dfs(board.size()-1, i, board);
            }
        }

        for (int i=0; i<board.size(); i++){     // first column
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i, 0, board);
            }
        }
        for (int i=0; i<board.size(); i++){     // last column
            if(!vis[i][board[0].size()-1] && board[i][board[0].size()-1]=='O'){
                dfs(i, board[0].size()-1, board);
            }
        }

        for(int i=1; i<board.size()-1; i++){
            for(int j=1; j<board[0].size()-1; j++){
                if(!vis[i][j] && board[i][j]=='O')   board[i][j]='X';
            }
        }
    }

    void dfs(int x, int y, vector<vector<char>>& board){
        vis[x][y]=1;
        if(board[x][y] == 'O'){
            for(int dx=-1; dx<=1; dx+=2){
                if(x+dx>=0 && x+dx<board.size()){
                    if(!vis[x+dx][y]){
                        dfs(x+dx, y, board);
                    }
                }
            }
            for(int dy=-1; dy<=1; dy+=2){
                if(y+dy>=0 && y+dy<board[0].size()){
                    if(!vis[x][y+dy]){
                        dfs(x, y+dy, board);
                    }
                }
            }
        }
    }
};