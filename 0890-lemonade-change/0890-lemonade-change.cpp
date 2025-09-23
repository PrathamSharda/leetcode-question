class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5=0;
        int count10=0;
        int count20=0;

        for(int it:bills)
        {
            int change=it-5;

            if(change==5)
            {
                if(count5==0)return false;
                count5--;
            }else if(change==15)
            {
                if((count10==0&&count5<3)||(count5==0&&count10>=0))return false;
                
                if(count10!=0)
                {
                    count10--;
                    count5--;
                }else{
                    count5-=3;
                }
            }

            if(it==5)count5++;
            else if (it==10)count10++;
            else count20++;
        }
        return true;
    }
};