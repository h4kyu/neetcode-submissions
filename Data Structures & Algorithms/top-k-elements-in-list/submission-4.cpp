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
        // auto comp{ [](const auto& a, const auto& b) { return a > b; } };
        // sort(freqVec.begin(), freqVec.end(), comp);

        // populate queue
        // priority_queue<pair<int, int>> pq(freqVec.cbegin(), freqVec.cend());    // max heap
        
        // freq buckets, freq as index
        vector<vector<int>> freqBuckets(nums.size() + 1);   // n + 1 possible frequencies

        for (const auto& p : freqVec) {
            freqBuckets[p.first].push_back(p.second);
        }

        vector<int> result;

        int index{static_cast<int>(nums.size())};
        while (k > 0) {
            if (!freqBuckets[index].empty()) {
                for (const auto n : freqBuckets[index]) {
                    if (k > 0) {
                        result.push_back(n);
                        --k;
                        continue;
                    }
                    break;
                }
            }
            --index;
        }

        // for (int i{0}; i < k; ++i) {
        //     // result[i] = freqVec[i].second;
        //     // result[i] = pq.top().second;
        //     // pq.pop();
        // }

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