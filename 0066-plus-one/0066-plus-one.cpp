class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int sum=0;
        int carry=0;
        for(int i=0;i<digits.size();i++)
        {
            sum=(digits[i]+carry);
            if(i==0)sum++;
            digits[i]=(sum)%10;
            carry=sum>9?1:0;
        }
        if(carry!=0)
        {
            digits.push_back(carry);
        }
        reverse(digits.begin(),digits.end());
        return digits;

    }
};