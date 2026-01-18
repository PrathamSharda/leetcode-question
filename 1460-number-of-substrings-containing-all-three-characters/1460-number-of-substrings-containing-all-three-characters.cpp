class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        vector<int>freq(3,-1);
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']=i;
            int minIndex=INT_MAX;
            for(int j=0;j<3;j++)
            {
                minIndex=min(minIndex,freq[j]);

            }
            if(minIndex==-1||minIndex==INT_MAX)continue;

            count+=minIndex+1;
        }
        return count;
    }
};