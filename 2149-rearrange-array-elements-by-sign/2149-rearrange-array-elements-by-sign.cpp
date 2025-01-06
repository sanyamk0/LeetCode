class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<int> pos, neg;
        for (auto it : nums) {
            if (it > 0)
                pos.push_back(it);
            else
                neg.push_back(it);
        }
        for (int i = 0; i < n / 2; i++) {
            v.push_back(pos[i]);
            v.push_back(neg[i]);
        }
        return v;
    }
};