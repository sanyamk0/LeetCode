//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> computePrefixFunction(const string& s) {
        int n = s.size();
        vector<int> prefix(n, 0);
        
        for (int i = 1; i < n; ++i) {
            int j = prefix[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = prefix[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            prefix[i] = j;
        }
        
        return prefix;
    }

    int minChar(string& s) {
        string combined = s + "#" + string(s.rbegin(), s.rend());
        vector<int> prefix = computePrefixFunction(combined);
        int longestPalindromicSuffixLength = prefix.back();
        return s.length() - longestPalindromicSuffixLength;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends