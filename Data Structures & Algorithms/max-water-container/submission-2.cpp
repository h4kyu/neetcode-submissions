class Solution {
public:
    int maxArea(const vector<int>& heights) {
        auto water = [&heights](int i, int j) {
            return (j - i)*min(heights[i], heights[j]);
        };
        auto l{0};
        int r{static_cast<int>(heights.size()) - 1};

        auto result{0};

        while (l < r) {
            auto w{water(l, r)};
            if (w > result) result = w;

            if (heights[l] <= heights[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }
};


/**

given two indices i, j
water = (j - i)*min(height[i], height[j])

- define two pointers l at index 0 and r at index heights.size()-1
- while l < r
    - compare water [l, r] to running max
    - if heights[l] <= heights[r]
        - l++
    - otherwise r--
- return max

*/

