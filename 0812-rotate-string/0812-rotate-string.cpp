class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return false;
        int p1=0;
        int p2=0;
        for(int i=0;i<s.size();i++)
        {
            for(int l=0;l<goal.size();l++)
            {
                if(s[i]==goal[l])
                {
                    int k=i;
                    int flag=0;
                    for(int j=l;j<s.size()+l;j++)
                    {
                        if(s[k%goal.size()]!=goal[j%(goal.size())])
                        {
                            flag=1;
                            break;
                        }
                        k++;

                    }
                    if(!flag)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
        



    }
};