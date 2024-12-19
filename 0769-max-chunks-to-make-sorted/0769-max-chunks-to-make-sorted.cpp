class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, maxSeen = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxSeen = std::max(maxSeen, arr[i]);
            if (maxSeen == i) {
                chunks++;
            }
        }
        return chunks;
    }
};