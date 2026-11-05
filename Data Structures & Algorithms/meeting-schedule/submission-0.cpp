/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 bool compare(Interval& x, Interval& y){
            return x.start<y.start;
        }
class Solution {
   
public:
    bool canAttendMeetings(vector<Interval>& intervals) 
    {
        
        sort(intervals.begin(),intervals.end(), compare);

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i].start< intervals[i-1].end) return false;
        }
        return true;
    }
};
