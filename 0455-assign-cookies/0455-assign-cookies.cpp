class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count=0;
        sort(s.begin(),s.end(),greater<int>());
        sort(g.begin(),g.end(),greater<int>());
        int j=0;
        for(int i=0;i<g.size();i++)
        {
            if(j>=s.size())break;

            if(s[j]>=g[i])
            {
                count++;
                j++;
            }
            
        }
        return count;
    }
};