class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charFreqS{};
        unordered_map<char, int> charFreqT{};
        for (char c : s) {
            ++charFreqS[c];
        }
        for (char c : t) {
            ++charFreqT[c];
        }
        return charFreqS == charFreqT;
    }
};
