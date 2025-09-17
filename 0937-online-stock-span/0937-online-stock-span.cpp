class StockSpanner {
    int count=0;
    stack<pair<int,int>>st;
public:
    StockSpanner() {
         count=0;
    }

    int next(int price) {
        int num=0;
        if(st.empty())
        {
            num=1;
        }else{
        while(!st.empty()&&st.top().first<=price)st.pop();
        if(!st.empty())
        num=count-st.top().second;
        else{
            num=count+1;
        }
        }
         st.push({price,count});
        count++;
        return num;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */