//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (charIndexMap.find(s[i]) != charIndexMap.end() && charIndexMap[s[i]] >= start)
                start = charIndexMap[s[i]] + 1;
            charIndexMap[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends