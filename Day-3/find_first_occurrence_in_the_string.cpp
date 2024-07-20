class Solution {
private:
    void createLps(vector<int>& lps, string s) {
        int n = lps.size();

        int len = 0;
        int i = 1;
        while (i < n) {
            if (s[len] == s[i]) {
                lps[i++] = ++len;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else {
                    lps[i++] = 0;
                }
            }
        }
    }

public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        vector<int> lps(n, 0);
        createLps(lps, needle);

        int i = 0;
        int j = 0;
        while ((m - i) >= (n - j)) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == n) {
                return i - j;
            } else if (i < m && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};
