class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int cnt = 0;
        long long pr = 1;
        unordered_map<long long, long long> mp1, mp2;
        for (auto it : nums1) {
            mp1[static_cast<long long>(it) * it]++;
        }
        for (int j = 0; j < n2; j++) {
            for (int k = j + 1; k < n2; k++) {
                pr = static_cast<long long>(nums2[j]) * nums2[k];
                cnt += mp1[pr];
            }
        }
        for (auto it : nums2) {
            mp2[static_cast<long long>(it) * it]++;
        }
        for (int j = 0; j < n1; j++) {
            for (int k = j + 1; k < n1; k++) {
                pr = static_cast<long long>(nums1[j]) * nums1[k];
                cnt += mp2[pr];
            }
        }
        return cnt;
    }
};