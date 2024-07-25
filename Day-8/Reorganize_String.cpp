class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        string ans = "";
        unordered_map<char, int> mp;
        for (auto& i : s)
            mp[i]++;
        for (auto i : mp)
            pq.push({i.second, i.first});

        while (pq.size() > 1) {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            ans += a.second;
            a.first--;
            ans += b.second;
            b.first--;
            if (a.first > 0)
                pq.push({a.first, a.second});
            if (b.first > 0)
                pq.push({b.first, b.second});
        }

        if (!pq.empty()) {
            if (pq.top().first > 1)
                return "";
            else
                ans += pq.top().second;
        }

        return ans;
    }
};
