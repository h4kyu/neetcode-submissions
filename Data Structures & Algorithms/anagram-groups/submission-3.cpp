class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> str2vector;

        for (const string& str : strs) {
            string temp{str};
            sort(temp.begin(), temp.end());
            str2vector[temp].push_back(str);
        }
        auto it{str2vector.begin()};
        vector<vector<string>> res;
        while (it != str2vector.end()) {
            res.push_back(it->second);
            ++it;
        }
        return res;
    }
};


/**
two words are anagrams if:
frequency of letters match

*/

/** O(N*LlogL)
two words are anagrams if:
sorted str match

- define map<string, vector<string>>
- iterate str : strs
    - map[sorted str].pushback(str)
- iterate map to construct and return vector<vector<str>>
*/