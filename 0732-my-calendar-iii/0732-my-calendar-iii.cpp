class MyCalendarThree {
public:
   map<int,int>mpp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        int maxi=0;
        int sum=0;
        mpp[startTime]++;
        mpp[endTime]--;
        for(auto it:mpp){
            sum+=it.second;
            maxi=max(maxi,sum);
        }

        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */