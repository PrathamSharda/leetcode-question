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

    bool Union(vector<int>&par,int x,int y)
    {
        int parX=unionFind(par,x);
        int parY=unionFind(par,y);
        if(parX!=parY)
        {
            if(rank[parX]>rank[parY])
            {
                par[parY]=parX;
                rank[parX]+=rank[parY];
            }else{
                par[parX]=parY;
                rank[parY]+=rank[parX];
            }
            return false;
        }
        return true;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int>par(n*m);
        rank.resize(n*m);

        for(int i=0;i<n*m;i++)
        {
            par[i]=i;
            rank[i]=1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vector<int>path={0,1,0};
                for(int k=0;k<2;k++)
                {
                    int a=i+path[k];
                    int b=j+path[k+1];

                    if(a>=n||b>=m||a<0||b<0)continue;
                    if(grid[i][j]!=grid[a][b])continue;

                    if(Union(par,i*m+j,a*m+b))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};