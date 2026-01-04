class Solution {
public:
    pair<bool,int> matcher(int number)
    {
        int sum=0;
        int count=0;
        for(int i=1;i<=sqrt(number);i++)
        {
            if(number%i==0)
            {
                
                sum+=i;
                count++;
                if(i!=(number/i))
                {
                    count++;
                    sum+=(number/i);
                }
            }
        }
        if(count!=4)return {false,0};
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