class Solution {
public:

    // follow [string length]#[string]...
    string encode(vector<string>& strs) {
        string encodedString{};
        for (string& str : strs) {
            encodedString.append(to_string(str.size()) + '#' + str);
        }
        return encodedString;
    }
// 4#abcd3#abc
//  ji
    vector<string> decode(string s) {
        vector<string> strs{};
        int i{0};
        while (i < s.size()) {
            int j{i};
            // find '#'
            while (s[j] != '#') {
                ++j;
            }
            int length{stoi(s.substr(i, j - i))};
            i = j + 1;
            strs.push_back(s.substr(i, length));
            j = i + length;
            i = j;
        }
        return strs;
    }
};
