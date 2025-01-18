class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xor_sum = 0;
        for (int num : derived)
            xor_sum ^= num;
        return xor_sum == 0;
    }
};