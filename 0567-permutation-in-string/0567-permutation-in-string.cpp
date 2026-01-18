class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        string tempString="";
      
        vector<int>freq(26,0);
      // cout<<s1<<" "<<s2<<endl;
        for(int i=0;i<s1.length();i++)
        {
            freq[s1[i]-'a']++;
        }
        int i=0;
        int prev=-1;
        
        while(i<s2.length())
        {
            if(freq[s2[i]-'a']>0)
            {
                int inc=1;
                int flag=0;
                if(s2.length()-i<s1.length())break;
                for(int j=i;j<i+s1.length();j++)
                {
                    freq[s2[j]-'a']--;
                    if(freq[s2[j]-'a']<0)
                    {
                        flag=1;
                        inc=j+1;
                        break;
                    }
                }
                if(flag==0)return true;

                for(int j=i;j<inc;j++)
                {
                   freq[s2[j]-'a']++; 
                }
                

            }
            i++;
        }
        return false;
    }
};