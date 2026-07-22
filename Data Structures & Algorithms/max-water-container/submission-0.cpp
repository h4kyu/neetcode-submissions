class Solution {
public:
/*
bad solution:
int maxProd
int left
int right
for i=0 to height.size()
    left = i
    right = height.size() - 1
    while right>left
        product = height[left]*height[right]
        if product>maxProd
            maxProd = product
            could also account for duplicate heights
        --right
*/
    int maxArea(vector<int>& heights) {
        int maxProd{0};
        int left{};
        int right{};
        for (int i{0}; i < heights.size(); ++i) {
            left = i;
            right = heights.size() - 1;
            while (right > left) {
                int product{0};
                if (heights[left] > heights[right]) {
                    product = heights[right]*(right-left);
                }
                else {
                    product = heights[left]*(right-left);
                }
                if (product > maxProd) {
                    maxProd = product;
                }
                --right;
            }
        }

        return maxProd;
    }
};
