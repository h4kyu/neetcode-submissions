class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*  intuitive solution:
            sort array
            --> store longest consecutive
            --> iterate over nums
                --> if next is +1, add to current sequence length
                --> else
                    1: check if current length > longest, replace if so
                    2: reset current sequence length and continue
            return longest consecutive
        */

        if (nums.size() == 0) return 0;

        int longest{1};
        int currSeqLength{1};

        sort(nums.begin(), nums.end());

        for (int i{1}; i < nums.size(); ++i) {
            int prevNum{nums[i - 1]};
            if (nums[i] == prevNum + 1) {
                ++currSeqLength;
            } else if (nums[i] == prevNum) {
                continue;
            } else {
                if (currSeqLength > longest) {
                    longest = currSeqLength;
                }
                currSeqLength = 1;
            }
        }
        if (currSeqLength > longest) {
            longest = currSeqLength;
        }
        return longest;
    }
};