class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> keyToGroup;
        for (const string& str : strs) {
            array<int, 26> freq{};
            for (char letter : str) ++freq[letter - 'a'];
            string key{to_string(freq[0])};
            for (size_t i{1}; i < 26; ++i) {
                key += ',' + to_string(freq[i]);
            }
            keyToGroup[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto& [key, group] : keyToGroup) {
            result.push_back(group);
        }
        return result;
    }
};


/**
two words are anagrams iff frequency of letters match

store frequencies per str as hashable key: 26-element arr

- define unordered_map<array<int, 26>, vector<string>>
- iterate str : strs
    - zero-initialize array<int, 26>
    - for every letter in str
        - increment corresponding element in array (char - 'a')
    - map[array].push_back(str)
- define vector<vector<string>>
- iterate map and populate result
*/