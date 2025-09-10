class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int,int>>st;

        vector<int>nge(asteroids.size(),-1);
        for(int i=0;i<asteroids.size();i++)
        {
            while(!st.empty()&&asteroids[i]<0 &&st.top().first<=abs(asteroids[i]))
            {
                nge[st.top().second]=abs(asteroids[i]);
                if(st.top().first==abs(asteroids[i]))
                {
                    nge[i]=0;
                    st.pop();
                    break;
                }
                
                st.pop();
            }
            if(!st.empty()&&asteroids[i]<0)
            {
                nge[i]=st.top().first;
            }
            if(asteroids[i]>0)
            {
                st.push({asteroids[i],i});
            }
        }

        for(auto it:nge)
        {
            cout<<it<<" ";
        }
        vector<int>Result;
        for(int i=0;i<nge.size();i++)
        {
            if(nge[i]!=-1)
            {
                continue;
            }
            Result.push_back(asteroids[i]);
        }
        return Result;
    }
};