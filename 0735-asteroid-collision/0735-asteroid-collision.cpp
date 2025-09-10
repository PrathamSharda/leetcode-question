class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int,int>>st;
        for(int i=0;i<asteroids.size();i++)
        {
            while(!st.empty()&&asteroids[i]<0 &&st.top().first<=abs(asteroids[i]))
            {
                asteroids[st.top().second]=0;
                if(st.top().first==abs(asteroids[i]))
                {
                    asteroids[i]=0;
                    st.pop();
                    break;
                }
                
                st.pop();
            }
            if(!st.empty()&&asteroids[i]<0)
            {
                asteroids[i]=0;
            }
            if(asteroids[i]>0)
            {
                st.push({asteroids[i],i});
            }
        }

        vector<int>Result;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]==0)
            {
                continue;
            }
            Result.push_back(asteroids[i]);
        }
        return Result;
    }
};