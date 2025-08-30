class Solution {
public:
    bool bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j,int parI,int parJ)
    {   
        vis[i][j]=1;
        vector<int>path={0,1,0,-1,0};
        for(int l=0;l<4;l++)
        {
            int x=i+path[l];
            int y=j+path[l+1];
            if(x>=grid.size()||y>=grid[0].size()||x<0||y<0)continue;

            if(grid[i][j]!=grid[x][y])continue;

            if(x==parI&&y==parJ)continue;

            if(vis[x][y]==1)return true;
            
            vis[x][y]=1;
           if(bfs(grid,vis,x,y,i,j))
           {
            return true;
           }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(vis[i][j]==0)
                {
                    if(bfs(grid,vis,i,j,-1,-1))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};