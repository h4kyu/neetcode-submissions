class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int upperIdx{numbers.size() - 1};
        int lowerIdx{0};
        while (upperIdx > lowerIdx) {
            int upperNum{numbers[upperIdx]};
            int lowerNum{numbers[lowerIdx]};
            if (upperNum + lowerNum == target) {
                return {lowerIdx + 1, upperIdx + 1};
            }
            if (upperNum + lowerNum > target) {
                --upperIdx;
            } else if (upperNum + lowerNum < target) {
                ++lowerIdx;
            }
        }
        return {};
    }
};
