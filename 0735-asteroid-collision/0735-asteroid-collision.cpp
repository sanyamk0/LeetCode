class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int asteroid : asteroids) {
            bool exploded = false;
            while (!stack.empty() && stack.back() > 0 && asteroid < 0) {
                if (abs(stack.back()) < abs(asteroid)) {
                    stack.pop_back();
                } else if (abs(stack.back()) == abs(asteroid)) {
                    stack.pop_back();
                    exploded = true;
                    break;
                } else {
                    exploded = true;
                    break;
                }
            }
            if (!exploded)
                stack.push_back(asteroid);
        }
        return stack;
    }
};