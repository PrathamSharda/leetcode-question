class Solution {
public:
    int totalFruit(vector<int>& fruits) {
          int left=0;
          int right=0;
          unordered_map<int,int>mp;
          int maxi=0;
         for(int i=0;i<fruits.size();i++)
          {
            mp[fruits[i]]++;
            if(mp.size()>2)
            {
                while(mp.size()>2&&left<i)
                {
                    mp[fruits[left]]--;
                    if(mp[fruits[left]]==0)mp.erase(fruits[left]);
                    left++;
                }
            }
            maxi=max(maxi,i-left+1);
          }
          return maxi;
    }
};