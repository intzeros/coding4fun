/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> starts(n), ends(n);
        for(int i = 0; i < intervals.size(); i++){
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        vector<Interval> rst;
        for(int i = 0, j = 0; i < n; i++){  // j is start of interval.
            if(i == n-1 || ends[i] < starts[i+1]){
                rst.push_back(Interval(starts[j], ends[i]));
                j = i+1;
            }
        }
        return rst;
    }
};
