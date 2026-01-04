class Solution {
public:
    pair<bool,int> matcher(int number)
    {

        vector<int>total;
        int sum=0;
        for(int i=1;i<=sqrt(number);i++)
        {
            if(number%i==0)
            {
                total.push_back(i);
                sum+=i;
                if(i!=(number/i))
                {
                    total.push_back(number/i);
                    sum+=(number/i);
                }
            }
        }
        if(total.size()!=4)return {false,0};
        return {true,sum};

    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            pair<bool,int>it=matcher(nums[i]);
            
            if(it.first)
            {

                sum+=it.second;
            }
        }
        return sum;
    }
};