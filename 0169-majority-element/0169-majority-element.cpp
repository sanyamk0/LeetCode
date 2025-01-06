class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, el;
        for (auto it : nums) {
            if (cnt == 0)
                el = it;
            if (it == el)
                cnt++;
            else
                cnt--;
        }
        return el;
    }
};