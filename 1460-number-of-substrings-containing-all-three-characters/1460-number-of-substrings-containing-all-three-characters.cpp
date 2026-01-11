class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>count(3,-1);
        int total=0;
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']=i;
            int mini=INT_MAX;
            for(int j=0;j<3;j++)
            {
                mini=min(mini,count[j]);
            }
            if(mini==-1)continue;
            total+=(mini)+1;
        }
        return total;
    }
};