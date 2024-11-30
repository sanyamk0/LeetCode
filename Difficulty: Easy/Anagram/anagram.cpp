//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
         if (s1.length() != s2.length())
            return false;
        vector<int> charCount(26, 0);
        for (char c : s1)
            charCount[c - 'a']++;
        for (char c : s2)
            charCount[c - 'a']--;
        for (int count : charCount)
            if (count != 0)
                return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends