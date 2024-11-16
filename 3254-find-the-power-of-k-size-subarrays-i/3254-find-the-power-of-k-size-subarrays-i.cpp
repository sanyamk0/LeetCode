class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> result(length - k + 1, -1);
        deque<int> indexDeque;
        for (int currentIndex = 0; currentIndex < length; currentIndex++) {
            if (!indexDeque.empty() &&
                indexDeque.front() < currentIndex - k + 1) {
                indexDeque.pop_front();
            }
            if (!indexDeque.empty() &&
                nums[currentIndex] != nums[currentIndex - 1] + 1) {
                indexDeque.clear();
            }
            indexDeque.push_back(currentIndex);
            if (currentIndex >= k - 1) {
                if (indexDeque.size() == k)
                    result[currentIndex - k + 1] = nums[indexDeque.back()];
                else
                    result[currentIndex - k + 1] = -1;
            }
        }
        return result;
    }
};