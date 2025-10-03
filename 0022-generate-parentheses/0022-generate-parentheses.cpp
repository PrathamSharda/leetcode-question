class Solution {
public:
    void generator(vector<string>&result,string& ans,int start,int close)
    {
        //if(close-start>1)return;
        if(start<0||close<0)return;
        else if(start==0&&close==0)
        {
           
            result.push_back(ans);
        }
        else if(start==close)
        {
            ans=ans+'(';
            generator(result,ans,start-1,close);
            ans=ans.substr(0,ans.length()-1);
        }else{
            ans=ans+'(';
            generator(result,ans,start-1,close);
            ans=ans.substr(0,ans.length()-1);
            ans=ans+')';
            generator(result,ans,start,close-1);
            ans=ans.substr(0,ans.length()-1);
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output="";
        generator(ans,output,n,n);
        return ans;
    }
};