class MyCalendarThree {
private:
    map<int,int> intervals;
    map<int,int> starts;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) 
    {
        intervals[start]++;
        intervals[end]--;
        int count=0,ans=0,inner=0;
        for(auto& i:intervals)
        {
            count+=i.second;
            ans=max(count,ans);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */