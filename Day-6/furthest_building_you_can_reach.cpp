class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        int b = 0;
        while (i < heights.size() - 1) {
            if (heights[i] < heights[i + 1])
                pq.push(heights[i + 1] - heights[i]);
            if (pq.size() > ladders) {
                b += pq.top();
                pq.pop();
                if (bricks < b)
                    return i;
            }
            i++;
        }

        return heights.size() - 1;
    }
};
