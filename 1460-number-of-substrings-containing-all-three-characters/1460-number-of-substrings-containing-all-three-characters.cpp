#include <bits/stdc++.h>

class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        
        int prefix=0;
        vector<int>len(3,-1);
        for(int i=0;i<s.length();i++)
        {
            int flag=0;
            len[s[i]-'a']=i;
            for(int j=0;j<3;j++)
            {
                if(len[j]==-1){
                    flag=1;
                    break;
                }
            }
            if(flag)continue;
            int minIndex=INT_MAX;
            for(int j=0;j<3;j++)
            {
                minIndex=min(minIndex,len[j]);
            }
            count+=minIndex+1;
        }
        return count;
    }
};