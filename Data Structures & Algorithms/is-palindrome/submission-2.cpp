class Solution {
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(const string& s) {
        auto length{s.size()};
        int l{0};
        int r{static_cast<int>(length) - 1};

        while (l < r) {
            while (l < r && !alphaNum(s[l])) {
                ++l;
            }
            while (r > l && !alphaNum(s[r])) {
                --r;
            }
            if (tolower(s[l]) != tolower(s[r])) return false;

            ++l;
            --r;
        }
        return true;
    }
};
