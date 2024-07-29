class Solution {
public:
    bool isPalin(int i, int j, string s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    void helper(string s, vector<string>& v, vector<vector<string>>& ans,
                int i) {
        if (i == s.size()) {
            ans.push_back(v);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (isPalin(i, j, s)) {
                v.push_back(s.substr(i, j + 1 - i));
                helper(s, v, ans, j + 1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        helper(s, v, ans, 0);

        return ans;
    }
};
