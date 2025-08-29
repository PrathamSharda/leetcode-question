class Solution {
public:
    // int unionFind(vector<int>&par,int x)
    // {
    //     if(par[x]==x)
    //     {
    //         return x;
    //     }
    //     return par[x]=unionFind(par,par[x]);
    // }
    // void Union()

    void bfs(vector<vector<char>>&board,int i,int j)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
         board[i][j]='$';
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            vector<int>path={0,-1,0,1,0};
            
            for(int l=1;l<5;l++)
            {
                int a=path[l-1]+x;
                int b=path[l]+y;

                if(a>=board.size()||b>=board[0].size()||a<0||b<0)continue;

                if(board[a][b]=='$'||board[a][b]=='X')continue;

                board[a][b]='$';

                // cout<<a<<" "<<b<<endl;
                q.push({a,b});
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        
        //checks for first and last coloumn
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O')
            {
                
                bfs(board,i,0);
            }
             if(board[i][board[0].size()-1]=='O')
            {
               
                bfs(board,i,board[0].size()-1);
            }
        }

        //first and last row
        for(int i=0;i<board[0].size();i++)
        {
            if(board[0][i]=='O')
            {
                
                bfs(board,0,i);
            }
             if(board[board.size()-1][i]=='O')
            { 
                // cout<<board.size()-1<<" "<<i<<endl;
                bfs(board,board.size()-1,i);
            }
        }

        //iterate over the rest and change the '$' to 'O'

        for (int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                 if(board[i][j]=='$')
                {
                    board[i][j]='O';
                }
            }
        }

    }
};