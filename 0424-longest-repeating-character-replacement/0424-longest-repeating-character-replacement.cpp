class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0;
        vector<int>count(26,0);
        int p1=0;
        int maxLength=0;
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'A']++;
            maxFreq=max(maxFreq,count[s[i]-'A']);
                while(i-p1-maxFreq+1>k)
                {
                    count[s[p1]-'A']--;
                    maxFreq=0;
                    for(int j=0;j<26;j++)
                    {
                        maxFreq=max(maxFreq,count[j]);
                    }
                    p1++;
                }
            
            maxLength=max(maxLength,i-p1+1);
        }
        return maxLength;
    }
};