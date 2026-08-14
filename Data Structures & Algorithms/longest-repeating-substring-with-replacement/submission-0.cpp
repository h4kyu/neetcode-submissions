class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> letterToFreq;
        auto l{0};
        auto maxLength{0};
        auto maxFreq{0};

        auto getMaxFreq = [&letterToFreq]() {
            auto m{0};
            for (auto [letter, freq] : letterToFreq) {
                m = max(m, freq);
            }
            return m;
        };

        for (int r{0}; r < s.size(); r++) {
            letterToFreq[s[r]]++;
            maxFreq = getMaxFreq();

            while (l < r && !(k >= (r - l + 1) - maxFreq)) {
                letterToFreq[s[l]]--;
                l++;
                maxFreq = getMaxFreq();
            }
            maxLength = max(maxLength, r-l+1);
        }
        return maxLength;
    }
};


/**
a window is valid iff:
    k >= window length - char of max freq   (ie. # of chars to be replaced)

- define map of letter freq
- define sliding window [l, r]
- track max length
- track max frequency in window
- iterate chars c in s
    - if window is valid
        - increment r to expand window
        - update freq map and max freq
    - otherwise increment l until window is valid
        - update freq map and max length
- return max length

*/
