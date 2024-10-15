//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        int n = arr.size(), cnt = 0, prefixSum = 0;
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = 1;
        for(int i = 0; i < n; i++) {
            prefixSum += arr[i];
            if (prefixSumMap.find(prefixSum - tar) != prefixSumMap.end())
                cnt += prefixSumMap[prefixSum - tar];
            prefixSumMap[prefixSum]++;
        }
        return cnt;
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
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends