class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<>>minHeap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(maxHeap.size()==0)
        {
            maxHeap.push(num);
        }else{
            if(maxHeap.top()>num)
            {
                maxHeap.push(num);
            }else{
                minHeap.push(num);
            }
        }
        if(minHeap.size()>maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }else if (maxHeap.size()>minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {

        if(maxHeap.size()==minHeap.size())
        {
            return (double)(maxHeap.top()+minHeap.top())/2;
        }else{
            return maxHeap.top();
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */