class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     if (s.length() != t.length()) return false;

    //     std::sort(s.begin(), s.end());
    //     std::sort(t.begin(), t.end());

    //     return s == t;
    // }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> freqS;
        unordered_map<char, int> freqT;

        for (int i{0}; i < s.length(); ++i) {
            freqS[s[i]]++;
            freqT[t[i]]++;
        }

        return freqS == freqT;
    }
};


/* O(nlogn + mlogm)
- exit early if lengths dont match
- sort and compare
*/

/* O(n + m)
- define hashmaps to store frequency of letters in each word
- iterate strings and populate hashmaps
- compare hashmaps
*/