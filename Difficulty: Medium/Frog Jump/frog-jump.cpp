//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int helper(int n, vector<int>& height, vector<int>& dp){
        if(n == 0)
            return 0;
        if (n == 1)
            return abs(height[1] - height[0]);
        if(dp[n] != -1)
            return dp[n];
        int left = helper(n - 1, height, dp) + abs(height[n] - height[n - 1]);
        int right = helper(n - 2, height, dp) + abs(height[n] - height[n - 2]);
        return dp[n] = min(left, right);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return helper(n - 1, height, dp);
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends