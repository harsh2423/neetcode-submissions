class MedianFinder {
public:
    priority_queue<int,vector<int>> smallheap;
    priority_queue<int,vector<int>, greater<int>> largeheap; 
    MedianFinder() {}
    
    void addNum(int num) 
    {
        smallheap.push(num);
        if(!largeheap.empty() && smallheap.top()>largeheap.top()){
            largeheap.push(smallheap.top());
            smallheap.pop();
        }

        if(smallheap.size()>largeheap.size()+1)
        {
            largeheap.push(smallheap.top());
            smallheap.pop();
        }

        if(largeheap.size()>smallheap.size()+1)
        {
            smallheap.push(largeheap.top());
            largeheap.pop();
        }
    }
    
    double findMedian() 
    {
        if(smallheap.size()==largeheap.size())
        {
            return (smallheap.top()+largeheap.top())/2.0;
        }    
        if(smallheap.size()>largeheap.size()) return smallheap.top();
        else return largeheap.top();
    }
};
