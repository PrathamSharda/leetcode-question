class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size())return -1;

        int p1=0;
        while(p1<haystack.size())
        {
            if(haystack[p1]==needle[0])
            {
                int flag=0;
                for(int i=0;i<needle.size();i++)
                {
                    if(p1+i>=haystack.size())
                    {
                        flag=1;
                        break;
                    }
                    
                    if(haystack[p1+i]!=needle[i])
                    {
                        flag=1;
                        break;
                    } 
                }
                if(!flag)return p1;

            }
            p1++;
        }

        return -1;
    }
};