class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        priority_queue<int> pq;

        for (auto i : tasks)
            freq[i - 'A']++;
        for (auto i : freq) {
            if (i != 0)
                pq.push(i);
        }
        queue<pair<int, int>> q;
        int time = 0;
        int top = 0;
        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                top = pq.top();
                pq.pop();
                top--;
                if (top != 0)
                    q.push({top, time + n});
            }

            if (!q.empty()) {
                if (q.front().second == time) {
                    pq.push(q.front().first);
                    q.pop();
                }
            }
        }

        return time;
    }
};
