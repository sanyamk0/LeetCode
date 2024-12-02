//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> computeLPSArray(const std::string& pat) {
        int m = pat.length();
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0)
                    len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    vector<int> search(string& pat, string& txt) {
        vector<int> indices;
        int n = txt.length(), m = pat.length();
        if (m == 0 || n < m)
            return indices;
        vector<int> lps = computeLPSArray(pat);
        int i = 0, j = 0;
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == m) {
                indices.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return indices;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends