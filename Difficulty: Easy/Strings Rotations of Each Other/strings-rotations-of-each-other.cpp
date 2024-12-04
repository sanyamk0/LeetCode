//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length())
            return false;
        string temp = s2 + "$" + s1 + s1;
        int n = temp.length();
        vector<int> arr(n, 0);
        int i = 1, len = 0;
        while (i < n) {
            if (temp[i] == temp[len]) {
                len++;
                arr[i] = len;
                i++;
            } else {
                if (len > 0)
                    len = arr[len - 1];
                else
                    i++;
            }
        }
        for (int a : arr)
            if (a == s1.length())
                return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends