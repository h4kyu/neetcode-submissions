class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> uniqueNums;
        for (const auto num : nums) {
            uniqueNums.insert(num);
        }
        auto maxLength{1};

        for (auto num : uniqueNums) {
            auto length{1};
            if (uniqueNums.count(num - 1)) continue;

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
