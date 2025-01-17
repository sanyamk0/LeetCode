class Solution {
public:
    bool present(vector<int> arr, int i) {
        for (auto it : arr)
            if (it == i)
                return true;
        return false;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int miss = 0;
        for (int i = 1; i < *max_element(arr.begin(), arr.end()); i++) {
            if (!present(arr, i))
                miss += 1;
            if (miss == k)
                return i;
        }
        if (miss == 0 || miss < k)
            return n + k;
        return -1;
    }
};