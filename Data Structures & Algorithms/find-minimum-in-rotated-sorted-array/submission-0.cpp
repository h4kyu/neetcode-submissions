class Solution {
public:
    int findMin(const vector<int> &nums) {
        size_t lo{0};
        size_t hi{nums.size() - 1};

        while (lo < hi) {
            size_t mid{lo + (hi - lo)/2};

            if (nums[mid] > nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};



/**

comparing curr against right endpoint, 
if curr is larger, min is guaranteed to live to its right.

- apply binary search
- while lo < hi
    - if nums[mid] > nums[hi]
        - lo = mid + 1
    - otherwise
        - hi = mid
return nums[lo]

*/






