class Solution {
public:
    vector<int>rank;
    int unionFind(vector<int>&par,int x)
    {
        if(par[x]==x)
        {
            return x;
        }
        return par[x]=unionFind(par,par[x]);
    }

    void Union(vector<int>&par,int x,int y)
    {
        int parX=unionFind(par,x);
        int parY=unionFind(par,y);

        if(parX==par.size()-1&&parY!=parX)
        {
            par[parY]=parX;
            rank[parX]+=rank[parY];
        
        }
        else if(parY==par.size()-1&&parY!=parX)
        {
            par[parX]=parY;
            rank[parY]+=rank[parX];
        }
        else if(parX!=parY)
        {
            if(rank[parX]>rank[parY])
            {
                par[parY]=parX;
                rank[parX]+=rank[parY];
            }else{
                par[parX]=parY;
                rank[parY]+=rank[parX];
            }
        }
    }

 
    void solve(vector<vector<char>>& board) {
        
        //checks for first and last coloumn
        int n=board.size();
        int m=board[0].size();
        vector<int>par(n*m+1,0);
        rank.resize(n*m+1);
        for(int i=0;i<=n*m;i++)
        {
            par[i]=i;
            rank[i]=1;
        }
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O')
            {
                Union(par,i*m,n*m);
            }
            if(board[i][board[0].size()-1]=='O')
            {
                 Union(par,i*m+(m-1),n*m);
            } 
        }
        for(int j=0;j<board[0].size();j++)
        {
            if(board[0][j]=='O')
            {
                Union(par,j,n*m);
            }
            if(board[board.size()-1][j]=='O')
            {
                Union(par,(n-1)*m+j,n*m);
            }
        }
        vector<int>path={0,1,0,-1,0};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(board[i][j]=='O')
                {

                
                for(int l=1;l<5;l++)
                {
                    int a=path[l-1]+i;
                    int b=path[l]+j;

                    if(a>=n||b>=m||a<0||b<0)continue;

                    if(board[a][b]=='X')continue;

                    Union(par,a*m+b,i*m+j);
                }

                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X')continue;
                if(unionFind(par,i*m+j)!=n*m)
                {
                    board[i][j]='X';
                }
            }
        }


    }
};