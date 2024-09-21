class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        for (int i = 0; i < n; i++) {
            int first = 0, flag = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    nge[i] = nums[j];
                    first = 1;
                    flag = 1;
                    break;
                }
            }
            if (!first) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] > nums[i]) {
                        nge[i] = nums[j];
                        flag = 1;
                        break;
                    }
                }
            }
            if (!flag)
                nge[i] = -1;
        }
        return nge;
    }
};