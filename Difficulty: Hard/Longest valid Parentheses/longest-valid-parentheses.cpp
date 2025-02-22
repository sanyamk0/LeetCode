//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        int maxLen = 0, open = 0, close = 0;
        for (char c : s) {
            if (c == '(') open++;
            else close++;
            if (open == close) maxLen = max(maxLen, 2 * close);
            else if (close > open) open = close = 0;
        }
        open = close = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') open++;
            else close++;
            if (open == close) maxLen = max(maxLen, 2 * open);
            else if (open > close) open = close = 0;
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends