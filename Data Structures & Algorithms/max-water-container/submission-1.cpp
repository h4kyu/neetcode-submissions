class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxProd{0};
        int left{0};
        int right{heights.size()-1};
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

            if (heights[left] > heights[right]) {
                --right;
            } else {
                ++left;
            }
        }
        return maxProd;
    }
};
