class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        unordered_set<char> unique;
        auto maxCount{0};
        auto l{0};
        auto r{0};

        for (int i{0}; i < s.size(); i++) {
            auto c{s[i]};

            if (unique.count(c)) {
                while (l < r && unique.count(s[r])) {
                    unique.erase(s[l]);
                    l++;
                }
            }
            unique.insert(c);
            ++r;
            maxCount = max(maxCount, r-l);
        }
        return maxCount;
    }
};


/**

- define window [l, r]
- define a set of characters in window
- OPTIONAL define array[128] of index at which ascii char was last seen
- track max count
- iterate char c in s
    - if c not in set
        - add to set
        - increment r
    - otherwise 
        - update max count
        - increment l until s[l] is not in set
        - add c to set
- return max count

*/