class Solution {
public:
    bool checkValidString(string s) {
        int maxi=0;
        int mini=0;

        for(auto it:s)
        {
            if(it=='(')
            {
                maxi++;
                mini++;
            }
            else if(it==')')
            {
                if(mini!=0)mini--;
                maxi--;
            }else{
                if(mini!=0)mini--;
                maxi++;
            }


            if(mini==-1||maxi==-1)return false;
        }
        if(mini!=0)return false;
        return true;
    }
};