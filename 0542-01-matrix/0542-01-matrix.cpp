class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)q.push({i,j});
            }
        }
        vector<vector<int>>result(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(result[x][y]!=INT_MAX)continue;
               
                result[x][y]=count;
                vector<int>path={0,1,0,-1,0};
                for(int j=0;j<4;j++)
                {
                    int a=x+path[j];
                    int b=y+path[j+1];
                    if(a<0||b<0)continue;
                    if(a>=mat.size()||b>=mat[0].size())continue;
                    if(mat[a][b]==0)continue;
                    if(result[a][b]!=INT_MAX)continue;
                    q.push({a,b});
                }
            }
            count++;
        }
        return result;
    }
};