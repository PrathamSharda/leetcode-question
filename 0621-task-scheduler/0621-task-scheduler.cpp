class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>mp(26,0);
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]-'A']++;
        }

        for(int i=0;i<26;i++)
        {
            if(mp[i]>0)
            {
                pq.push(mp[i]);
            }
        }

        int count=0;
        while(!pq.empty())
        {
            vector<int>ele;
            for(int i=0;i<n+1;i++)
            {
                if(pq.size()!=0)
                {
                    int newEle=pq.top();
                    pq.pop();
                    newEle--;
                    count++;
                    if(newEle!=0)
                    {
                        ele.push_back(newEle);
                    }
                }
                else{
                    if(ele.size()!=0)count++;
                }

            }
            for (auto it:ele)
            {
                pq.push(it);
            }
        }
        return count;
    }
};