//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        stack<string> strStack;
        stack<int> countStack;
        string res;
        int k = 0;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + c - '0';
            } else if (c == '[') {
                strStack.push(res);
                countStack.push(k);
                res.clear();
                k = 0;
            } else if (c == ']') {
                string temp = res;
                int count = countStack.top();
                countStack.pop();
                for (int i = 0; i < count - 1; i++)
                    res += temp;
                res = strStack.top() + res;
                strStack.pop();
            } else {
                res += c;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends