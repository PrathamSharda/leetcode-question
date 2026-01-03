class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            vector<int>count(256,0);
            for(int j=0;j<board[0].size();j++)
            {
                count[board[i][j]]++;
                
                if(board[i][j]!='.'&&count[board[i][j]]>1)
                {
                    return false;
                }
            }
        }
      //  cout<<1<<endl;
        for(int i=0;i<board[0].size();i++)
        {
            vector<int>count(256,0);
            for(int j=0;j<board.size();j++)
            {
                count[board[j][i]]++;
                if(board[j][i]!='.'&&count[board[j][i]]>1)
                {
                    return false;
                }
            }
        }
      //  cout<<2<<endl;
         int totalT=0;
        int totalB=0;
            for(int i=0;i<board.size();i++)
            {
                vector<int>count(256,0);
               
                if(i!=0&&i%3==0)
                {
                    totalT+=3;
                    totalB=0;
                }else{
                    if(i!=0)
                    totalB+=3;
                }
                for(int j=totalT;j<totalT+3;j++)
                {
                    for(int k=totalB;k<totalB+3;k++)
                    {
                        count[board[j][k]]++;
                        if(board[j][k]!='.'&&count[board[j][k]]>1)return false;
                    }
                }
                
            }
        //    cout<<3<<endl;
        return true;
    }
};