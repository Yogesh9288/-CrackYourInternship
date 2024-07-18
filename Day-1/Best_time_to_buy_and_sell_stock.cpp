class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minel = INT_MAX;
        int ans = 0;
        for (auto& i : prices) {
            minel = min(minel, i);
            int res = i - minel;
            ans = max(ans, res);
        }

        return ans;
    }
};
