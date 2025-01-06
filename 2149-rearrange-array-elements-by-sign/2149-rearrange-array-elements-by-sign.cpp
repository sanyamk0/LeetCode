class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int pos = 0, neg = 1;
        for (auto it : nums) {
            if (it > 0) {
                v[pos] = it;
                pos += 2;
            } else {
                v[neg] = it;
                neg += 2;
            }
        }
        return v;
    }
};