class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {

        unordered_set<int> uniqueNums(nums.cbegin(), nums.cend());
        auto maxLength{0};

        for (auto num : uniqueNums) {
            if (uniqueNums.count(num - 1)) continue;
            
            auto length{1};
            while (uniqueNums.count(num + 1)) {
                ++length;
                ++num;
            }
            if (length > maxLength) maxLength = length;
        }

        return maxLength;
    }
};

/**

- iterate nums to populate a set of unique numbers
- track max length
- iterate set
    - track sequence length
    - if num-1 exists in set, move on
    - otherwise we are at tail of sequence. iterate num+1 to find length
- return max length

*/
