class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int maxCount=0;
        unordered_map<int,int>mp;
        int p1=0;
        int p2=0;
        while(p2<fruits.size())
        {
            mp[fruits[p2]]++;

            if(mp.size()>2)
            {
                while(mp.size()>2&&p1<p2)
                {
                    mp[fruits[p1]]--;
                    if(mp[fruits[p1]]==0)
                    {
                        mp.erase(fruits[p1]);
                    }
                    p1++;
                }
            }

            if(mp.size()<=2)
            {
                maxCount=max(maxCount,p2-p1+1);
            }
            p2++;
        }
        return maxCount;
    }
};