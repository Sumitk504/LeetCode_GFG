#include<bits/stdc++.h>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left;
        vector<int> right;
        //  to find the index of NSL(Nearest smallest ele to left)
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty())
                left.push_back(-1);
            else
                left.push_back(st.top());
            st.push(i);
        }
        // clear the stack to be reused
        while (!st.empty())
            st.pop();

        //  to find the index of NSR(Nearest smallest ele to right)
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty())
                right.push_back(n);
            else
                right.push_back(st.top());
            st.push(i);
        }
        reverse(right.begin(), right.end());
        
        int res=0;
        for (int i = 0; i < n; i++)
            res = max(res,heights[i]*(right[i] - left[i] - 1));
        return res;
    }
};