class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strsMap; // sorted str --> anagrams

        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            strsMap[key].push_back(str);
        }

        vector<vector<string>> result{};
        for (auto& [key, group] : strsMap) {
            result.push_back(group);
        }

        return result;
    }
};
