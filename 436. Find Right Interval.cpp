//https://leetcode.com/problems/find-right-interval/

class Solution {

struct Interval{
    int i;
    int j;
    int originalPosition;
};

static bool compare(Interval a, Interval b){
    return a.i < b.i;
}
    
public:
    //O(n log n) time and O(n) space complexity
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> indexes;
        indexes.reserve(intervals.size());
        
        if (intervals.size() == 1){
            //corner case, example [1,1] is right interval of itself
            if (intervals[0][0] == intervals[0][1])
                indexes.push_back(0);
            else
                indexes.push_back(-1);
            return indexes;
        }
        
        vector<Interval> orderedIntervals(intervals.size());
        fill(orderedIntervals, intervals); //O(n) time
        //order by start i in ascending order; note that each start is unique
        sort(orderedIntervals.begin(), orderedIntervals.end(), compare); //O(n log n) time
        
        //O(n log n) time
        for (int i = 0; i < intervals.size(); i++){
            if (intervals[i][0] == intervals[i][1])
                indexes.push_back(i);
            else
                indexes.push_back(binarySearch(orderedIntervals, intervals[i]));
        }
        
        return indexes;
    }

private:
    //O(n) time and O(1) space
    void fill(vector<Interval> &orderedIntervals, vector<vector<int>> intervals){
        for (unsigned int i = 0; i < intervals.size(); i++){
            Interval currentInterval;
            currentInterval = {intervals[i][0], intervals[i][1], (int) i};
            orderedIntervals[i] = currentInterval;
        }
    }

private:
    //O(log n) time and O(1) space
    int binarySearch(vector<Interval> orderedIntervals, vector<int> interval){
        int begin = 0, end = orderedIntervals.size() - 1;
        int positionMinimum = 0;
        
        //if the greater start is less than the end of our interval, there's no solution
        if (orderedIntervals[end].i < interval[1]){
            return -1;
        }
        
        while(begin <= end){
            int mid = ((unsigned int) begin + end) >> 1;
            int start = orderedIntervals[mid].i;
            
            //the minimum possible
            if (start == interval[1]){
                return orderedIntervals[mid].originalPosition;
            } 
            
            if (start < interval[1]){
                begin = mid + 1;
            } else {
                positionMinimum = orderedIntervals[mid].originalPosition;
                end = mid - 1;
            }
        }
        
        return positionMinimum;
    }
};
