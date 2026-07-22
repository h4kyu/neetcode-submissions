// iterate over array, store number to frequency map
// create 2D array of size n, where index = frequency
// for each number in map, append to bucket in appropriate index
// return numbers in first k indices from n, ingoring values of 0

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq{};
        // first pass
        for (int num : nums) {
            ++freq[num];
        }

        vector<vector<int>> freqIndex(nums.size() + 1);

        for (const auto& pair : freq) {
            int key{pair.first};
            int value{pair.second};
            freqIndex[value].push_back(key);
        }

        // get first k
        vector<int> topK{};
        for (size_t i{freqIndex.size() - 1}; i > 0; --i) {
            for (int n : freqIndex[i]) {
                topK.push_back(n);

                if (topK.size() == k ) return topK;
            }
        }

        return topK;
    }
};
