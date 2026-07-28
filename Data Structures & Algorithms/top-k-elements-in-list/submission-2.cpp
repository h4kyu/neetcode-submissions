class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numToFreq{};
        
        for (const int num : nums) ++numToFreq[num];

        vector<pair<int, int>> freqVec;
        freqVec.reserve(numToFreq.size());
        for (const auto& [num, freq] : numToFreq) {
            freqVec.push_back({freq, num});
        }

        // sort in descending order
        auto comp{ [](const auto& a, const auto& b) { return a > b; } };
        sort(freqVec.begin(), freqVec.end(), comp);
        
        vector<int> result(k);

        for (int i{0}; i < k; ++i) {
            result[i] = freqVec[i].second;
        }

        return result;
    }
};

/** O(n + mlogm) OR O(n + klogm)

- define map numToFreq
- iterate nums
    - ++numToFreq[num]
- iterate map
    - populate vector with num-freq pairs
- sort vector by pair->second
- return top k pair->first

OR

- populate priority queue with num-freq pairs by pair->second
- pop k pair->first

*/

/** O(n)

- define map numToFreq
- iterate nums
    - ++numToFreq[num]
- define a vector of length n+1 of vectors
- iterate map
    - pushback vector with pair->first at [pair->second] index
- walk back vector to return top k

*/