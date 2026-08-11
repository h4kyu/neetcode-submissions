class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        const int length{static_cast<int>(nums.size())};

        for (auto i{0}; i < length; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            auto l{i+1};
            auto r{length-1};

            while (l < r) {
                auto s{nums[i] + nums[l] + nums[r]};

                if (s == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l-1]) {
                        ++l;
                    }
                } else if (s > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return result;
    }
};


/**

- sort nums
- iterate nums
    - define pointers j=i+1, k=nums.size()-1
    - if sum of nums[i]+nums[l]+nums[r] = 0
        - record the triplet
        - increment l to a unique value to skip duplicate triplets
    - if sum > 0, decrement r
    - if sum < 0, increment l
    - return result

*/
