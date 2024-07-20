class Solution:
    def validPalindrome(self, s: str) -> bool:
        def check(l: int, r: int) -> bool:
            while l <= r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1
            return True

        i, j = 0, len(s) - 1
        while i <= j:
            if s[i] != s[j]:
                # Check if removing either the left or right character makes the string a palindrome
                return check(i + 1, j) or check(i, j - 1)
            else:
                i += 1
                j -= 1
        return True
