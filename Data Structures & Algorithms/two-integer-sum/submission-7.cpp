class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;
        for (size_t i{0}; i < nums.size(); ++i) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());

        size_t l{0}; size_t r{nums.size() - 1};

        while (l < r) {
            auto sum{v[l].first + v[r].first};
            auto a = v[l].second, b = v[r].second;

            if ( sum == target ) return a > b ? vector<int>{b, a} : vector<int>{a, b};
            if ( sum > target ) --r;
            if ( sum < target ) ++l;
        }
        // return a > b ? {b, a} : {a, b};
    }
};


/**

- define v = vector<pair<value, index>>
- traverse nums and populate v
- sort v
- define indices l and r
- while l < r
    - if v[l].first + v[r].first = target, return {v[l].second, v[r].second}
    - if sum > target, --r;
    - if sum < target, ++l;
*/