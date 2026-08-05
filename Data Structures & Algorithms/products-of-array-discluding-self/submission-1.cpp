class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProducts(nums.size());
        vector<int> suffixProducts(nums.size());

        auto prefix{1};
        for (size_t i{0}; i < nums.size(); ++i) {
            prefixProducts[i] = prefix;
            prefix *= nums[i];
        }
        auto suffix{1};
        for (size_t j{nums.size()}; j-- > 0; ) {
            suffixProducts[j] = suffix;
            suffix *= nums[j];
        }

        vector<int> output(nums.size());
        for (size_t k{0}; k < nums.size(); ++k) {
            output[k] = prefixProducts[k] * suffixProducts[k];
        }

        return output;
    }
};


/**

- iterate nums once, store total product
- for each num, populate result with total/num

OR without div

- define prefix prod and suffix prod vectors
- iterate left to right, store prefix products in prefix vec
- iterate right to left, store suffix products in suffix vec
- at each index, populate result with corresponding prefix and suffix product

*/