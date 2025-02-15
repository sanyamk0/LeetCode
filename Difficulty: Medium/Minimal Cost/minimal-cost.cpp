//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int ind, vector<int> arr, int k, vector<int>& dp){
        dp[0] = 0;
        for(int i = 1; i <= ind; i++){
            int cost = INT_MAX;
            for(int j = 1; j <= k; j++){
                if(i - j >= 0){
                    cost = dp[i - j] + abs(arr[i] - arr[i - j]);
                    dp[i] = min(dp[i], cost);
                }
            }
        }
        return dp[ind];
    }
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        vector<int> dp(n, INT_MAX);
        return helper(n - 1, arr, k, dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends