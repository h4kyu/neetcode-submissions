class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> distinct;

        for (auto num : nums) {
            if (distinct.find(num) != distinct.end()) {  // num is in set
                return true;
            } else {
                distinct.insert(num);
            }
        }
        return false;
    }
};

/* O(N)

- define set
- define duplicate counter
- iterate array
    - if not in set, add to set
    - if in set, ++counter
*/