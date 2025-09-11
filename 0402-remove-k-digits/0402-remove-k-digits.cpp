class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        if(k==num.size())return "0";
        for(char c:num)
        {
            while(k!=0&&!st.empty()&&st.top()>c)
            {
                st.pop();
                k--;
            }
            st.push(c);
            
        }

        if(k!=0)
        {
            while(k!=0)
            {
                st.pop();
                k--;
            }
        }
        string output="";
        stack<char>st2;
        while(!st.empty())
        {
            st2.push(st.top());
            st.pop();
        }
        int flag=0;
        while(!st2.empty())
        {

            if(flag==0&&st2.top()=='0')
            {
                st2.pop();
                continue;

            }else{
                flag=1;
                output.push_back(st2.top());
                st2.pop();
            }
        }
        if(output=="")return "0";
        return output;
    }
};