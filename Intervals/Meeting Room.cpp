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


 class cmp{
public:
    bool operator() (const Interval a , const Interval b) const {
        return (a.start <= b.start) ;
    }
 };

class Solution {
public:
    
    bool canAttendMeetings(vector<Interval> &intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp());
        // bool 
        for(int i=1;i<n;i++){
            int e = intervals[i-1].end;
            int s = intervals[i].start;

            if(e <= s){
                continue;
            }
            return false;
        }

        return true;
    }
};
