//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int MOD = 1e9 + 7;
    long long memo(int n, vector<int>& dp){
        if(n <= 1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = (memo(n - 1, dp) + memo(n - 2, dp)) % MOD;
    }
    long long int topDown(int n) {
        vector<int> dp(n + 1, -1);
        return memo(n, dp);
    }
    long long tab(int n, vector<int>& dp){
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return dp[n];
    }
    long long int bottomUp(int n) {
        vector<int> dp(n + 1, -1);
        return tab(n, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends