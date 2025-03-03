class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        list<int> less, equal, greater;
        for (auto num : nums) {
            if (num < pivot)
                less.push_back(num);
            else if (num > pivot)
                greater.push_back(num);
            else
                equal.push_back(num);
        }
        less.insert(less.end(), equal.begin(), equal.end());
        less.insert(less.end(), greater.begin(), greater.end());
        for (auto num : less)
            ans.push_back(num);
        return ans;
    }
};