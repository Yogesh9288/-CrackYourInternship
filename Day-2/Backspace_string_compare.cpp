class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string s1;
        for (auto& i : s) {
            if (i == '#') {
                if (s1.size() > 0)
                    s1.pop_back();
            } else
                s1.push_back(i);
        }

        string t1;
        for (auto& i : t) {
            if (i == '#') {
                if (t1.size() > 0)
                    t1.pop_back();
            } else
                t1.push_back(i);
        }

        return s1 == t1;
    }
};
