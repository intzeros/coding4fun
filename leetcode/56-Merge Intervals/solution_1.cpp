/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval& node1, const Interval& node2){
    if(node1.start == node2.start) return node1.end < node2.end;
    return node1.start < node2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int i = 0, n = intervals.size();
        vector<Interval> rst;
        while(i < n){
            if(i+1 < n && intervals[i].end < intervals[i+1].start){
                rst.push_back(intervals[i]);
                i++;
            }else{
                Interval newInterval(intervals[i].start, intervals[i].end);
                i++;
                while(i < n && intervals[i].start <= newInterval.end){
                    newInterval.end = max(newInterval.end, intervals[i].end);
                    i++;
                }
                rst.push_back(newInterval);
            }
        }
        return rst;
    }
};
