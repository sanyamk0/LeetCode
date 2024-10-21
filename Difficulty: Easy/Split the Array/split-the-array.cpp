//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

const int MOD = 1e9 + 7;

class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int n = arr.size(), xorAll = 0;
        for (int num : arr)
            xorAll ^= num;
        if (xorAll != 0)
            return 0;
        long result = 1;
        for (int i = 0; i < n -1; i++)
            result = (result * 2) % MOD;
        result = (result - 1 + MOD) % MOD;
        return result;
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
        Solution obj;
        int ans = obj.countgroup(arr);
        cout << ans << endl;
    }
}

// } Driver Code Ends