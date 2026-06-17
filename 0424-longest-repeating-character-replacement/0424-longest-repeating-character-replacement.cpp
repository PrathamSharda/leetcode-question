class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>hash(26,0);
        int maxLength=0;
        int left=0;
        int maxFreq=0;
        for(int i=0;i<s.length();i++)
        {
            hash[s[i]-'A']++;
            maxFreq=max(maxFreq,hash[s[i]-'A']);
            
            if((i-left)+1-maxFreq>k)
            {
                while(((i-left)+1-maxFreq>k)&&left<i)
                {
                    hash[s[left]-'A']--;
                    left++;
                    maxFreq=0;
                    for(int j=0;j<hash.size();j++)
                    {
                        
                        maxFreq=max(maxFreq,hash[j]);
                    }
                }
            }
            maxLength=max(maxLength,(i-left)+1);
        }
        return maxLength;
    }
};