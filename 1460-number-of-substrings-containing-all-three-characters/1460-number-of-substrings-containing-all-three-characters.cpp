class Solution {
public:
    int numberOfSubstrings(string s) {
       // vector<int>count(3,-1);
        int total=0;
        queue<int>a;
        queue<int>b;
        queue<int>c;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')a.push(i);
            else if(s[i]=='b')b.push(i);
            else c.push(i);
        }
        for(int i=0;i<s.length();i++)
        {
              if(a.empty()||b.empty()||c.empty())break;
            int indA=a.front();
            int indB=b.front();
            int indC=c.front();
            if(i==indA)
            a.pop();
            if(i==indB)
            b.pop();
            if(i==indC)
            c.pop();

             int maxNum=max(max(max(indA,indB),max(indC,indB)),max(max(indC,indB),max(indA,indC)));
             total+=(s.length()-maxNum);
            

          
        }
       
        return total;
    }
};