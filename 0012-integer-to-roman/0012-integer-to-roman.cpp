class Solution {
public:
    string intToRoman(int num) {
        int power=3;
        string output="";
        while(num&&power>=0)
        {
            int base=pow(10,power);
            int temp=num/base;
            if(power==3)
            {
                for(int i=0;i<temp;i++)
                {
                    output+='M';
                }
            }
            else if(power==2)
            {
                if(temp==9)
                {
                    output+="CM";
                }else if (temp==4)
                {
                    output+="CD";
                }else{
                    if(temp>=5)
                    {
                        output+='D';
                        for(int i=0;i<temp-5;i++)
                        {
                            output+='C';
                        }
                    }else{
                        for(int i=0;i<temp;i++)
                        {
                            output+='C';
                        }
                    }
                }
            }else if(power==1){
                if(temp==9)
                {
                    output+="XC";
                }else if (temp==4)
                {
                    output+="XL";
                }else{
                    if(temp>=5)
                    {
                        output+='L';
                        for(int i=0;i<temp-5;i++)
                        {
                            output+='X';
                        }
                    }else{
                        for(int i=0;i<temp;i++)
                        {
                            output+='X';
                        }
                    }
                }
            }else{
                  if(temp==9)
                {
                    output+="IX";
                }else if (temp==4)
                {
                    output+="IV";
                }else{
                    if(temp>=5)
                    {
                        output+='V';
                        for(int i=0;i<temp-5;i++)
                        {
                            output+='I';
                        }
                    }else{
                        for(int i=0;i<temp;i++)
                        {
                            output+='I';
                        }
                    }
                }
            }
            num=num%base;
            power--;
        }
        return output;
    }
};