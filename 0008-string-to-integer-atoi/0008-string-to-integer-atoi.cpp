class Solution {
public:
    int myAtoi(string s) {
        long long num=0;
        vector<int>nums;
        int op=0;
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0'&&s[i]<='9')nums.push_back(s[i]-'0');
            else if(nums.size()==0&&s[i]=='-'&&op==0)
            {
                flag=1;
                op++;
            }
            else if(nums.size()==0&&s[i]=='+'&&op==0)
            {
                op=1;
                continue;
            }
            else{
                if(s[i]==' '&&nums.size()==0&&op==0)continue;
                break;
            }
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i>9&&nums[i]!=0)
            {
                num=INT_MAX;
                if(flag)num++;
            }
            else{
            long long part=pow(10,i)*nums[i];
            num+=part;
            }
            if(num>=INT_MAX&&flag!=1)
            {
                return INT_MAX;
            }else if((num*-1)<=INT_MIN)return INT_MIN;

        }
        if(flag)num=num*-1;
        return num;
    }
};