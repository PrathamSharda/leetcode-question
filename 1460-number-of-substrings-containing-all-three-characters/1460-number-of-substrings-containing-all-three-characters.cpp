class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0;
        queue<int>qa;
        queue<int>qb;
        queue<int>qc;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a')qa.push(i);
            else if(s[i]=='b')qb.push(i);
            else qc.push(i);
        }
        
        for(int i=0;i<s.length();i++)
        {
            if(qa.empty()||qb.empty()||qc.empty())break;
            int indexA=qa.front();
            int indexB=qb.front();
            int indexC=qc.front();

            int maxIndex=max(max(max(indexA,indexB),max(indexB,indexC)),max(indexC,indexA));
            count+=(s.length()-maxIndex);
            if(i==indexA)qa.pop();
            else if(i==indexB)qb.pop();
            else qc.pop();
        }
        return count;
    }
};