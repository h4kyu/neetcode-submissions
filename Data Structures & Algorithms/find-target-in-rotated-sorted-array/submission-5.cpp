class Solution {
public:
    int search(vector<int>& nums, const int target) {
        // find min
        size_t lo{0};
        size_t hi{nums.size() - 1};
        size_t mid{lo + (hi - lo)/2};
        
        while (lo < hi) {
            if (nums[mid] > nums[hi]) {     // min must be to the right of mid
                lo = mid + 1;
            } else {
                hi = mid;
            }
            mid = lo + (hi - lo)/2;
        }

        size_t m{lo};

        auto at = [&](size_t i) {
            return nums[(i + m) % nums.size()];
        };

        lo = 0;
        hi = nums.size() - 1;
        mid = lo + (hi - lo)/2;
        while (lo < hi) {
            if (target > at(mid)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
            mid = lo + (hi - lo)/2;
        }
        return (at(lo) == target) ? (lo + m) % nums.size() : -1;
    }
};


/**

find index of min, m
- perform binary search
    - if nums[mid] > nums[hi]
        - lo = mid + 1
    - otherwise hi = mid
- m = lo

i = (i + m - 1) % (n-1)
- apply binary search for target with the above correction for indices

*/
