class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        int left=0;
        vector<int>hash(26,0);
        vector<int>hash1(26,0);
        for(int i=0;i<s1.size();i++)
        {
            hash[s1[i]-'a']++;
            hash1[s2[i]-'a']++;
        }
        for(int i=s1.size();i<s2.size();i++)
        {
            int flag=0;
            for(int j=0;j<26;j++)
            {
                if(hash[j]!=hash1[j])
                {
                    flag=1;
                    continue;
                }
            }
            if(flag==0)return true;

            hash1[s2[left]-'a']--;
            left++;
            hash1[s2[i]-'a']++;
            
        }
        int flag=0;
            for(int j=0;j<26;j++)
            {
                if(hash[j]!=hash1[j])
                {
                    flag=1;
                    continue;
                }
            }
            if(flag==0)return true;

            return false;

    }
};