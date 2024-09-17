class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    int flag = 0;
                    for (int k = j; k < n2; k++) {
                        if (nums2[k] > nums2[j]) {
                            ans.push_back(nums2[k]);
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag)
                        ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};