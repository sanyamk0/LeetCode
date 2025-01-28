class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int cnt = 0;
        long long sq=1;
        long long pr=1;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                for (int k = j + 1; k < n2; k++) {
                     sq = static_cast<long long>(nums1[i]) * nums1[i];
                     pr = static_cast<long long>(nums2[j]) * nums2[k];
                    if (sq == pr) {
                        cnt++;
                        // sq = 1, pr = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < n1; j++) {
                for (int k = j + 1; k < n1; k++) {
                     sq = static_cast<long long>(nums2[i]) * nums2[i];
                     pr = static_cast<long long>(nums1[j]) * nums1[k];
                    if (sq == pr) {
                        cnt++;
                        // sq = 1, pr = 1;
                    }
                }
            }
        }
        return cnt;
    }
};