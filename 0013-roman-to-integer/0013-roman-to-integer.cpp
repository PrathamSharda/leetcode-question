class Solution {
public:
    int romanToInt(string s) {
        char prev=' ';
        unordered_map<char,int>mp;
        mp[' ']=0;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int count=0;
      for(int i=s.size()-1;i>=0;i--)
      {
        if(mp[prev]>mp[s[i]])
        {
            count-=mp[s[i]];
        }else{
            count+=mp[s[i]];
        }
        prev=s[i];
      }
      return count;
    }
};