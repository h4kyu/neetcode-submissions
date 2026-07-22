class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> num2index;
        for (size_t i{0}; i < nums.size(); ++i) {
            num2index[nums[i]] = i;
        }
        for (int idx{0}; idx < nums.size(); ++idx) {
            auto a{nums[idx]};
            auto complement{target - a};
            auto it{num2index.find(complement)};
            
            if (it != num2index.end()) {
                int otherIdx{static_cast<int>(it->second)};
                if (idx == otherIdx) continue;
                return idx > otherIdx ? vector<int>{otherIdx, idx} : vector<int>{idx, otherIdx};
            }
        }
    }
};


/** O(nlogn)

- define v = vector<pair<value, index>>
- traverse nums and populate v
- sort v
- define indices l and r
- while l < r
    - if v[l].first + v[r].first = target, return {v[l].second, v[r].second}
    - if sum > target, --r;
    - if sum < target, ++l;
*/

/** O(n)

- define unordered map of num to index
- traverse nums and populate map
- for num in nums:
    - let complement = target - num
    - if map.find(complement), return ordered {num index, map.find(complement)}

*/