//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> numCount;
        int pairCount = 0;
        for (int num : arr)
            numCount[num]++;
        for (const auto& entry : numCount) {
            int num = entry.first;
            if (numCount.find(num + k) != numCount.end())
                pairCount += entry.second * numCount[num + k];
            if (k > 0 && numCount.find(num - k) != numCount.end())
                pairCount += entry.second * numCount[num - k];
        }
        return pairCount / 2;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends