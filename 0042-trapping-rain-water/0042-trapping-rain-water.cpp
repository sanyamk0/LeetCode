class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty())
                    break;
                int distance = i - stk.top() - 1;
                int bounded_height =
                    min(height[i], height[stk.top()]) - height[top];
                water += distance * bounded_height;
            }
            stk.push(i);
        }

        return water;
    }
};