class Solution {
public:
    bool is_in_set(set<int>& mySet, int num) {
        if (mySet.find(num) != mySet.end()) return true;
        return false;
    }
    bool hasDuplicate(vector<int>& nums) {
        set<int> numsSeen{};
        for (int i{0}; i < nums.size(); ++i) {
            int num{nums[i]};
            if (is_in_set(numsSeen, num)) {
                return true;
            } else {
                numsSeen.insert(num);
            }
        }
        return false;
    }
};
