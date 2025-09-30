class Solution {
public:
    int minBitFlips(int start, int goal) {
        string a="";
        string b="";

        while(start)
        {
            if(start%2==0)
            {
                a+='0';
            }else{
                a+='1';
            }
            start=start/2;
        }
         while(goal)
        {
            if(goal%2==0)
            {
                b+='0';
            }else{
                b+='1';
            }
            goal=goal/2;
        }
        int size=min(a.length(),b.length());
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]!=b[i])count++;
        }
        if(a.length()>size)
        {
            for(int i=size;i<a.length();i++)
            {
                if(a[i]!='0')count++;
            }
        }
        else if(b.length()>size){
            for(int i=size;i<b.length();i++)
            {
                if(b[i]!='0')count++;
            }
        }
        return count;
    }
};