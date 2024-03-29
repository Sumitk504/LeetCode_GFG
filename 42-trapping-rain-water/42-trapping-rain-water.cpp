class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL[n];
        int maxR[n];

        // Max element to the left side
        maxL[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            maxL[i] = max(maxL[i-1], height[i]);
        }


        // Max element to the right side
        maxR[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--)
        {
            maxR[i] = max(maxR[i+1], height[i]);
        }


        // water on above each building and summation of total water
        int water[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            water[i] = min(maxL[i], maxR[i]) - height[i];
            sum += water[i];
        }
        return sum;
    }
};