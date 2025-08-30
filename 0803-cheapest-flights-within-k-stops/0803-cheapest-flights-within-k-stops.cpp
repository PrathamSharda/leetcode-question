class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto it:flights)
        {
            int from=it[0];
            int to=it[1];
            int price=it[2];

            adj[from].push_back({to,price});
        }


        queue<pair<pair<int,int>,int>>q;

        int count=0;

        q.push({{src,0},0});
        vector<int>dis(n,1e9);
        dis[src]=0;
        while(!q.empty())
        {
            int num=q.front().first.first;
            int count=q.front().first.second;
            int price=q.front().second;
            q.pop();
            if(count>k)continue;
            count++;
            for(auto it:adj[num])
            {
                auto[adjNode,weight]=it;

                if(dis[adjNode]>weight+price)
                {
                    dis[adjNode]=weight+price;
                    
                    q.push({{adjNode,count},dis[adjNode]});
                }

            }
        }

        return dis[dst]>=1e9?-1:dis[dst];

    }
};