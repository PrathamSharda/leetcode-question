class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1)return dividend;
        long long times=0;
        int sign=0;
        if(dividend<0||divisor<0)sign++;
        if(dividend<0&&divisor<0)sign--;
        long long divi=abs( (long long )dividend);
        long long dis=abs((long long )divisor);
        while(divi>0)
        {
            long long sum=dis;
            long long p=1;
            int count=0;
            while(sum<=divi)
            {
                sum=dis*p;
                p*=2;
                count++;
            }
            divi-=(dis*pow(2,count-2));
            
            times+=pow(2,count-2);
        }

        return sign==1?-1*times<-2147483648?-2147483648:-1*times:times>2147483647?2147483647:times;
        
    }

};