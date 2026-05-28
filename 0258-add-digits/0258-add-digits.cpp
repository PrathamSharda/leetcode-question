class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        int temp=num;
        while(temp)
        {
            sum+=temp%10;
            temp=temp/10;
        }
        
        if(num/10!=0)
        {
            sum=addDigits(sum);
        }
        return sum;
    }
};